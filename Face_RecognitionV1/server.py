"""
Serve webcam images from a Redis store using Tornado.
Usage:
   python server.py
"""

import numpy as np
import base64
import time
import cv2
import coils
import redis
import pandas as pd
from tornado import websocket, web, ioloop
from io import BytesIO
MAX_FPS = 100

face_cascade = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_frontalface_alt2.xml')
font = cv2.FONT_HERSHEY_SIMPLEX

class IndexHandler(web.RequestHandler):
    """ This is our Handler for the root static page. """
    def get(self):
        self.render('index.html')

class SocketHandler(websocket.WebSocketHandler):
    """ This is our Handler for the websocket URL. """
    
    def __init__(self, *args, **kwargs):
        """ We do this to Initialize the Redis store and framerate monitor. """

        super(SocketHandler, self).__init__(*args, **kwargs)
        self._store = redis.Redis()
        self._fps = coils.RateTicker((1, 5, 10))
        self._prev_image_id = None

    def open(self):
        print("websocket opened")

    def on_message(self, message):
        """ Retrieve image ID from database until different from last ID,
        then retrieve image, de-serialize, encode and send to client. """

        while True:
            time.sleep(1./MAX_FPS)
            image_id = self._store.get('image_id')
            if image_id != self._prev_image_id:
                break
        self._prev_image_id = image_id
        image_byte = self._store.get('image')
        image = np.frombuffer(image_byte, dtype=np.uint8)  ## Interpret a buffer as a 1-dimensional array / turns into np array.
        images_gray = cv2.imdecode(image, cv2.IMREAD_GRAYSCALE)
        
            # This is required for opencv. Face recognition code below.
        faces = face_cascade.detectMultiScale(images_gray, 1.1, 5) ## Next, we detect the faces

        for (x, y, w, h) in faces:  # This will find our coordinates and y
            x1 = x
            x2 = x + w
            y1 = y
            y2 = y + h
          #  print("diagonal point 1(x1, y1) = ({},{})".format(x1, y1)) # This would be top left corner 
          #  print("diagonal point 2(x2, y2) = ({},{})".format(x2, y2)) # This would be top right corner 
        if len(faces) > 0:
            #print("[INFO] found {0} faces!".format(len(faces)))
            #GPIO.output(18,GPIO.HIGH)
            #if x1 >= 250 and x2 <= 500:
                # print("[INFO] found {0} faces!".format(len(faces)))
                # GPIO.output(18,GPIO.HIGH)
            if x1 < 200: # If our x coordinates is less than 225, then we move our face more left to the center, so  our face gets recognize
                self._store.set('move_position', "move left")
            elif x2 > 400: #if our x coordinates is greater than 475, then we move our face more right to the center, so our face gets recognize
                self._store.set('move_position', "move right")
            else:
                self._store.set('move_position', "found faces")
        else:
            self._store.set('move_position', "No Faces")

        for (x, y, w, h) in faces:   ## We draw a rectangle around the faces so we can see it correctly
            cv2.rectangle(images_gray, (x, y), (x+w, y+h), (255, 0, 0))         ## The faces will be a list of coordinates
            cv2.putText(images_gray, 'Myface', (x, y), font, fontScale=1, color=(255,70,120),thickness=2)
    
        retval, frame = cv2.imencode('.jpg', images_gray) # frame is memory buffer of jpg image
        value = np.array(frame).tobytes()
        image_byte = base64.b64encode(value)
        self.write_message(image_byte)



    # Print object ID and the framerate.
        text = '{} {:.2f}, {:.2f}, {:.2f} fps'.format(id(self), *self._fps.tick())
        print(text)

app = web.Application([
    (r'/', IndexHandler),
    (r'/ws', SocketHandler),    
])

if __name__ == '__main__':
    app.listen(9000)
    ioloop.IOLoop.instance().start()