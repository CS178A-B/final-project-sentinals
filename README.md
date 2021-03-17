# CS178A-B-Template: Nerf Sentry

## Table of Contents
- [Overview](#overview)
- [Usage](#usage)
- [How To Run](#how-to-run)
- [Diagrams](#diagrams)
- [Dependencies](#dependencies)

## Overview
Our project is an embedded system implementation that utilizes microcontrollers, servos, a camera, and a Nerf blaster. Put together, we have a Nerf Sentry that can serve as both a surveilance and entertainment device that fires upon detecting the presence of any person without the need of user input like a remote control.

<img src="https://github.com/CS178A-B/final-project-sentinals/blob/main/readme_visuals/NerfSentryFrontJPG.JPG" width="700" height="500"/>

## Team
<a href="https://github.com/eduardor626" target="_blank"><img src="https://avatars1.githubusercontent.com/u/33262466?s=400&u=c6b16422f4524bd8951a4989a7c85fbc6c010f84&v=4" align="left" height="30px">Eduardo Rocha</a>

<a href="https://github.com/B-Tran" target="_blank"><img src="https://avatars0.githubusercontent.com/u/43649007?s=400&v=4" align="left" height="30px">Brandon Tran </a>

<a href="https://github.com/sfazli96" target="_blank"><img src="https://avatars2.githubusercontent.com/u/43709736?s=400&v=4" align="left" height="30px">Sameh Fazli </a>

<a href="https://github.com/LukeTheChang" target="_blank"><img src="https://avatars3.githubusercontent.com/u/43716206?s=400&v=4" align="left" height="30px">Luccas Chang </a>

## Usage
Demo:

[![Demo](https://img.youtube.com/vi/DEM7JmdwIdw/0.jpg)](https://www.youtube.com/watch?v=DEM7JmdwIdw)

<Screenshot of application>

## How To Run

1. Setup components in the similiar as the [overall system diagram](#overall-system-diagram-with-notable-wirings) under [diagrams](#diagrams). Specific wirings are annotated. For other fields, such as VCC or GND, you can wire them accordingly to your convienience it through a breadboard or through the available ports of an Arduino. 
2. Follow the steps in the readme of the Face_RecognitionV1 directory to set up the face recognition module and app notification side of the project.
3. Using the Arduino IDE, upload the file named "Horizontal_Movement.ino" from the Horizontal_Movement directory into the Arduino Uno that is labeled "arduino uno r3 - 1" in the overall system diagram below.
4. Using the Arduino IDE, upload the file named "Motor_Driver.ino" from the Motor_Driver directory into the Arduino Uno that is labeled "arduino uno r3 - 2" in the overall system diagram below.
5. If they are not running, run the "client.py" and "server.py" files from the Face_RecognitionV1 directory. You sentry should now be able to detect any any one facing towards the usb camera.

## Diagrams

#### Overall System Diagram with Notable Wirings:

<img src="https://github.com/CS178A-B/final-project-sentinals/blob/Development/readme_visuals/cs178_nerfboys_wiringdiagram.png"/>

#### State Machines:

The following two are state machines that we are able to implement to some extent

* Horizontal Movement:

<img src="https://github.com/CS178A-B/final-project-sentinals/blob/Development/readme_visuals/h_motor_sm.png"/>

* State Machine for Trigger Pulling:

<img src="https://github.com/CS178A-B/final-project-sentinals/blob/Development/readme_visuals/Trigger_SM.jpg"/>

* State Machine for Firing Signal:

<img src="https://github.com/CS178A-B/final-project-sentinals/blob/Development/readme_visuals/Driver_SM.jpg"/>

### Pictures and Progress:

Being an embedded system project, we do not have a graphical user interface or anything of that sort yet. In its place, we have a rendering of what we envisioned for our implementation at the very beginning of the first quarter.

<img src="https://github.com/CS178A-B/final-project-sentinals/blob/main/readme_visuals/image6.png" width="300" height="300" />

In Milestone One, we have two major components in development: the Nerf blaster itself and the base/platform on which the blaster will be mounted on. Below is the dissassembled Nerf blaster with the components needed for it to power ON and fire. We also took away the need for the 6 C batteries needed to power the Blaster and instead attached a voltage booster to an AC to DC power supply. Decreasing the overall weight of our Blaster.  

<img src="https://github.com/CS178A-B/final-project-sentinals/blob/main/readme_visuals/NerfBlasterBase.JPG" width="700" height="500"/>

We begin addressing the need for horizontal movement in Milestone Two, approximately the latter half of the first quarter. What we ended up doing  was cutting a wooden platform on which the blaster will be placed upon. We also cut another wooden board of similar dimensions and cut a hole in the center for a servo to fit through. In between these two wooden boards, we put a metal ring on both boards in which, in between, ball bearings are present. A wooden block is placed above the servo. This configuration assists the servo in moving the blaster above.

<img src="https://github.com/CS178A-B/final-project-sentinals/blob/main/readme_visuals/IMG_2266.jpg" width="500" height="500"/>

At around between Milestone Two and Milestone Three, the first half of the second quarter, we decided to build the main base which is what the Nerf Sentry will be planted on. The main base will look similar to an open box. The top of this main base is sandwiched with the base of the Nerf Blaster.

<img src="https://github.com/CS178A-B/final-project-sentinals/blob/main/readme_visuals/NerfSentryFrontJPG.JPG" width="700" height="500"/>

For Milestone Three, we organize the components of the Nerf Sentry in a more organized fashion so that the wires are not all over the place and that most of our components are in one place. Milestone Four, around the last half of the second quarter, deals more with being able to implement some form of Android notification and improving the performance of the face recognition, with one issue being improving the framerate. The images below show the project in around the second quartere with labels of some of the notable component, followed by screenshots of the Android app and the notifications it receives.

<img src="https://github.com/CS178A-B/final-project-sentinals/blob/main/readme_visuals/MainBase.JPG" width="700" height="500"/>

<img src="https://github.com/CS178A-B/final-project-sentinals/blob/Development/readme_visuals/app_notification.png" width="200" height="300"/> 
<img src="https://github.com/CS178A-B/final-project-sentinals/blob/Development/readme_visuals/app_screenshot.png" width="200" height="300"/>


## Dependencies
Install Node Package Manager (npm). [Helpful Documentation](https://www.npmjs.com/get-npm)

Pip Install opencv-python [Documentation](https://pypi.org/project/opencv-python/)

arduino-libraries/servo [Repository](https://github.com/arduino-libraries/Servo) 

