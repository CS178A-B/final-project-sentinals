# How to run Facial Recognition
   To run on Raspberry pi, Follow these Steps
Steps:
1. First Open Command Line
2. Type cd wherever you save it on you computer i.e Desktop, Documents, etc.
3. Then in filename type python detectface.py. 
4. There your camera should show your face that it is being recognized.
5. To exit out of the program press Escape Key


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

References: https://github.com/adarsh1021/facedetection (used simple python implementation to recognize face)
                                                          https://stackoverflow.com/questions/21596281/how-does-one-convert-a-grayscale-image-to-rgb-in-opencv-python (Used for converting grayscale image to rgb)
https://pypi.org/project/opencv-python/ (used for to download opencv libraries and commands)

