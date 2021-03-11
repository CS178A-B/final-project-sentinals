import numpy as np
import cv2
import time
import redis
import coils
import os 
import sys
import RPi.GPIO as GPIO
from signal import signal, SIGINT
from sys import exit

GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)
GPIO.setup(18,GPIO.OUT)
GPIO.setup(23,GPIO.OUT)
GPIO.setup(24,GPIO.OUT)

face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_alt2.xml')
notif_flag = 0
prevTime = 0
## This will get our web camera 
#cap = cv2.VideoCapture(0)
font = cv2.FONT_HERSHEY_SIMPLEX

# These are command line argument, we cab Retrieve command line arguments.
width = None if len(sys.argv) <= 1 else int(sys.argv[1])
height = None if len(sys.argv) <= 2 else int(sys.argv[2])

# This will create the video capture object, will retry if it fails contiously
max_sleep = 5.0
cur_sleep = 0.1
while True:
    cap = cv2.VideoCapture(-1)   # Create the opencv webcam
    cap.set(3,282)
    cap.set(4,212)
    if cap.isOpened():
        break
    print('not opened, sleeping {}s'.format(cur_sleep))
    time.sleep(cur_sleep)
    if cur_sleep < max_sleep:
        cur_sleep *= 2
        cur_sleep = min(cur_sleep, max_sleep)
        continue
    cur_sleep = 0.1

# This creates a client to the Redis store, database.
store = redis.Redis()

# Set video dimensions, if given.
if width: cap.set(cv2.CAP_PROP_FRAME_WIDTH, width)
if height: cap.set(cv2.CAP_PROP_FRAME_HEIGHT, height)


# Monitor the framerate at 1s, 5s, 10s intervals.
fps = coils.RateTicker((1, 5, 10))

# Repeatedly capture current image, encode it, convert it to bytes and push
# it to Redis database. Then create unique ID, and push it to database as well.
try:
    while True:
        retval, frame = cap.read()
        if frame is None:
            time.sleep(0.5)
            continue
        retval, frame = cv2.imencode('.jpg', frame) # frame is memory buffer of jpg image
        value = np.array(frame).tobytes()
       # print(np.array(frame).dtype)
        store.set('image', value)
        
        image_id = os.urandom(4)
        store.set('image_id', image_id)
        image_position = store.get('move_position') ## Get string informations from server side
        image_position = image_position.decode('utf-8')
        #turn_off = store.get('off')

        if image_position:
        #    print(image_position)
            #print("[INFO] found {0} faces!".format(len(faces)))
            #GPIO.output(18,GPIO.HIGH)
            #if x1 >= 250 and x2 <= 500:
               # print("[INFO] found {0} faces!".format(len(faces)))
               # GPIO.output(18,GPIO.HIGH)
            if image_position == 'move left': # If our x coordinates is less than 225, then we move our face more left to the center, so  our face gets recognize
                print("move left")
                notif_flag = 1
                GPIO.output(18,GPIO.LOW)
                GPIO.output(23,GPIO.HIGH)
                GPIO.output(24,GPIO.LOW)

            elif image_position == 'move right': #if our x coordinates is greater than 475, then we move our face more right to the center, so our face gets recognize
                print("move right")
                notif_flag = 1
                GPIO.output(18,GPIO.LOW)
                GPIO.output(23,GPIO.LOW)
                GPIO.output(24,GPIO.HIGH)
            elif image_position == 'found faces':
                print("FIRE!!!") #Now, we are in the center of the camera, face detected, now shoot.
                if notif_flag == 0:
                    exec(open('firebase_server.py').read())
                    notif_flag = 1
                GPIO.output(18,GPIO.HIGH)
                GPIO.output(23,GPIO.LOW)
                GPIO.output(24,GPIO.LOW)
            else:
                print("No face") #No person is in scope of the camera so turn off everything
                notif_flag = 0
                GPIO.output(18,GPIO.LOW)
                GPIO.output(23,GPIO.LOW)
                GPIO.output(24,GPIO.LOW)

except KeyboardInterrupt:
    print("exiting!!")
    GPIO.output(18,GPIO.LOW)
    GPIO.output(23,GPIO.LOW)
    GPIO.output(24,GPIO.LOW)
    exit()
    
    # Print the framerate.
    # text = '{:.2f}, {:.2f}, {:.2f} fps'.format(*fps.tick())
    # print(text)

