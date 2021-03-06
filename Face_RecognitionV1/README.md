# How to run Facial Recognition with server and client
   To run on Raspberry pi, Follow these Steps
Steps:
1. First Open Command Line
2. Type cd wherever you save it on you computer i.e Desktop, Documents, etc.
3. Then cd into Face_RecognitionV1
4. Type in one terminal python client.py and in another terminal python server.py
5. Then open up a broswer i.e. google chrome, Mozilla, Internet Explorer, etc
6. Type in http://localhost:9000 (port is 9000) or type in IP address of computer http://192.168.x.x:9000 
7. Then a video output will appear in the browser. Face is being detected as well
8. Go back to server.py terminal and it will say in the terminal that face is detected, move left or move right

IMPORTANT: You must run create your virtual environment in this directory with this name venv/. venv/ has to be the virtual environment name.

Requirements:
1. You need a PC/Desktop that runs on Linux or Download Ubuntu on Windows. Either works.
2. Download OpenCV2
https://pypi.org/project/opencv-python/ , If the command from the link doesn't work, run this command sudo apt install python3-opencv. Doing so all you need to install is libopencv-dev for step 6. 
3. Get the face_cascade file from this github or create your own include it in your directory folder
https://github.com/adarsh1021/facedetection/blob/master/haarcascade_frontalface_default.xml
4. Find any image (person or anime is fine) that ends with .png, jpg, jpeg, etc.
5. Include this image in the folder directory.
6. Need to install this command: sudo apt-get install libopencv-dev in the command line
7. Install pip in order to use openCV2, run this command: python -m pip install --user numpy scipy matplotlib ipython jupyter pandas sympy nose and pip install opencv-python
8. You have to install, pip install RPi.GPIO to get the signal to the LED on the breadboard (this is for input and output from raspberry pi to the breadboard)
8. Both commands run those in your home directory i.e Desktop, Documents, etc.
9. Upgrade pip just in case of errors -> pip install --upgrade pip
10. Or other option download anaconda https://docs.anaconda.com/anaconda/install/linux/ Follow the instructions on the website
11. Then go back to step 2 to follow rest of instructions and OpenCV2 should be install through anaconda. (Optional) Make an python environment to save your dependencies, saves time.
12. Voila! You should be good to run and play around with the facial recognition. (If there is a step missing, then please repeat the process once more. If there is still errors, then type this command: sudo apt-update && sudo apt-upgrade on command line to check your operating system.)

References/Sources: https://github.com/adarsh1021/facedetection (used simple python implementation to recognize face)
                                                          https://stackoverflow.com/questions/21596281/how-does-one-convert-a-grayscale-image-to-rgb-in-opencv-python (Used for converting grayscale image to rgb)
https://pypi.org/project/opencv-python/ (used for to download opencv libraries and commands)
https://github.com/vmlaker/hello-websocket (Used for redis database, server/client and client/server)
https://quantum-inc.medium.com/remote-video-streaming-with-face-detection-d52ce2d71419 (Helpful for face recognition)
