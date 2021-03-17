# How to run Facial Recognition with server and client.

App Notification Side:
1. Install Android Studio in your machine. In a terminal, run "sudo pip install firebase-admin" https://firebase.google.com/docs/admin/setup. In Android Studio, open the project named "cs178_MyFirstApp."
2. Connect an Android device to your machine and enable debugging.
3. Make sure the device is selected on Android Studio and run "debug." Doing so will install and run the app on your device.
4. Check the debug log or console in Android studio. Look for a log that starts with "D/TAG: the token refreshed: ..." Copy the string that follows it, that is your device's unique token.
5. In the file named "firebase_server.py", assign the token saved in the previous step into the variable named 'registration_token' in line 22.
6. Copy the path of the 'google-services...json' file and paste that path into the "cred" variable in line 16 of the "firebase_server.py" file. Your 'firebase_server.py' file is now ready to send notification alerts to your specific Android device and your Android device is now ready to receive alerts of an intruder being fired upon.

Server Side: 
1. Open Command Line
2. cd into final-project-sentinals/Face-RecognitionV1/
3. Run python server.py

Client Side on Raspberry pi: 
1. First Open Command Line
2. Type cd wherever you save it on you computer i.e Desktop, Documents, etc.
3. Then cd into Face_RecognitionV1
4. Type in one terminal python client.py
5. Then open up a broswer i.e. google chrome, Mozilla, Internet Explorer, etc on preferably laptop/desktop
6. Type in IP address of computer http://192.168.x.x:9000 
7. Then a video output will appear in the browser. Face is being detected as well
8. Go back to client.py terminal and it will say in the terminal that face is detected, move left or move right
9. Notification is also being sent to firebase as well.
IMPORTANT: You can run requirements.txt wherever u created your virtual environment. To run requirements.txt, run the command pip install -r requirements.txt in the terminal. It will download all the dependices you need. 


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


References/Sources: https://github.com/adarsh1021/facedetection (used simple python implementation to recognize face), 
                                                          https://stackoverflow.com/questions/21596281/how-does-one-convert-a-grayscale-image-to-rgb-in-opencv-python (Used for converting grayscale image to rgb),
https://pypi.org/project/opencv-python/ (used for to download opencv libraries and commands), 
https://github.com/vmlaker/hello-websocket (Used for redis database, server/client and client/server), 
https://quantum-inc.medium.com/remote-video-streaming-with-face-detection-d52ce2d71419 (Helpful for face recognition), 
https://firebase.google.com/docs/admin/setup (setup of firebase server), 
https://firebase.google.com/docs/cloud-messaging/send-message?authuser=0 (sending notification to a specific device), 
https://firebase.google.com/docs/cloud-messaging/android/client (retrieving a device's token),
