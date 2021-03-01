import numpy as np
import cv2
import time
import redis
import coils
import os 
import sys
#import RPi.GPIO as GPIO

#GPIO.setmode(GPIO.BCM)
#GPIO.setwarnings(False)
#GPIO.setup(18,GPIO.OUT)
#GPIO.setup(23,GPIO.OUT)
#GPIO.setup(24,GPIO.OUT)

face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_alt2.xml')

prevTime = 0
## This will get our web camera 
#cap = cv2.VideoCapture(0)
font = cv2.FONT_HERSHEY_SIMPLEX

# Retrieve command line arguments.
width = None if len(sys.argv) <= 1 else int(sys.argv[1])
height = None if len(sys.argv) <= 2 else int(sys.argv[2])

# Create video capture object, retrying until successful.
max_sleep = 5.0
cur_sleep = 0.1
while True:
    cap = cv2.VideoCapture(-1)
    if cap.isOpened():
        break
    print('not opened, sleeping {}s'.format(cur_sleep))
    time.sleep(cur_sleep)
    if cur_sleep < max_sleep:
        cur_sleep *= 2
        cur_sleep = min(cur_sleep, max_sleep)
        continue
    cur_sleep = 0.1

# Create client to the Redis store.
store = redis.Redis()

# Set video dimensions, if given.
if width: cap.set(3, width)
if height: cap.set(4, height)

# Monitor the framerate at 1s, 5s, 10s intervals.
fps = coils.RateTicker((1, 5, 10))

# Repeatedly capture current image, encode it, convert it to bytes and push
# it to Redis database. Then create unique ID, and push it to database as well.
while True:
    retval, frame = cap.read()
    if frame is None:
        time.sleep(0.5)
        continue
    retval, frame = cv2.imencode('.jpg', frame)
    value = np.array(frame).tobytes()
    store.set('image', value)
    image_id = os.urandom(4)
    store.set('image_id', image_id)

    # Print the framerate.
   # text = '{:.2f}, {:.2f}, {:.2f} fps'.format(*fps.tick())
   # print(text)

#while True:
#    retval, frame = cap.read()
#    if not retval:
#        break
#    _, img = cap.read()              ## This ets each frame from the video, cap.read returns 2 variables flag - indicate frame is correct and 2nd is f

   # img = cv2.imread('Z.png')
   # gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)   # This method only works on gray skin images, so we have to convert the gray scale to rgb image
    coeffs = np.array([0.114, 0.587, 0.229])
    images_gray = (frame.astype(np.float) * coeffs).sum(axis=-1)
    images_gray = images_gray.astype(frame.dtype)
    faces = face_cascade.detectMultiScale(images_gray, 1.1, 5) ## Next, we detect the faces

    for (x, y, w, h) in faces:  # This will find our coordinates and y
        x1 = x
        x2 = x + w
        y1 = y
        y2 = y + h
        print("diagonal point 1(x1, y1) = ({},{})".format(x1, y1)) # This would be top left corner 
        print("diagonal point 2(x2, y2) = ({},{})".format(x2, y2)) # This would be top right corner
    if len(faces) > 0:
        #print("[INFO] found {0} faces!".format(len(faces)))
        #GPIO.output(18,GPIO.HIGH)
        #if x1 >= 250 and x2 <= 500:
           # print("[INFO] found {0} faces!".format(len(faces)))
           # GPIO.output(18,GPIO.HIGH)
        if x1 < 200: # If our x coordinates is less than 225, then we move our face more left to the center, so  our face gets recognize
            print("move left")
#            GPIO.output(18,GPIO.LOW)
#            GPIO.output(23,GPIO.HIGH)
#            GPIO.output(24,GPIO.LOW)

        elif x2 > 600: #if our x coordinates is greater than 475, then we move our face more right to the center, so our face gets recognize
            print("move right")
#            GPIO.output(18,GPIO.LOW)
#            GPIO.output(23,GPIO.LOW)
#            GPIO.output(24,GPIO.HIGH)
        else:
            print("[INFO] found {0} faces!".format(len(faces))) #Now, we are in the center of the camera, face detected, now shoot.
#            GPIO.output(18,GPIO.HIGH)
#            GPIO.output(23,GPIO.LOW)
#            GPIO.output(24,GPIO.LOW)
    else:
        print("No face") #No person is in scope of the camera so turn off everything
#        GPIO.output(18,GPIO.LOW)
#        GPIO.output(23,GPIO.LOW)
#        GPIO.output(24,GPIO.LOW)

    curTime = time.time()
    sec = curTime - prevTime
    prevTime = curTime
    fps = 1/(sec)
    str = "FPS : %0.1f" % fps 
    for (x, y, w, h) in faces:   ## We draw a rectangle around the faces so we can see it correctly
        cv2.rectangle(img, (x, y), (x+w, y+h), (255, 0, 0))         ## The faces will be a list of coordinates
        cv2.putText(img, 'Myface', (x, y), font, fontScale=1, color=(255,70,120),thickness=2)
    cv2.putText(frame, 'Number of Faces Detected: ' + str, (0,  100), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0))
    #cv2.imshow('img', frame) ## Last we show the image
    x = cv2.waitKey(30) & 0xff
    
    if x==27:
        break
## Press escape to exit the program
cap.release()
