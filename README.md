# CS178A-B-Template: Nerf Sentry

## Table of Contents
- [Overview](#overview)
- [Usage](#usage)
- [How To Run](#how-to-run)
- [Diagrams](#diagrams)
- [Dependencies](#dependencies)

## Overview
Our project is an embedded system implementation that utilizes microcontrollers, servos, a camera, and a Nerf blaster. Put together, we have a Nerf Sentry that fires upon detecting the presence of any person.

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

At this moment, two major components are working independently: the openCV facial recognition and the sentry blaster. For facial recognition, an implementation using openCV2 is stored in a Raspberry Pi. The implementation is able to return footage from a webcam connected to the Raspberry Pi where, if a face is recognized, the implementation outlines a rectangle around the face. 

For the sentry blaster, a servo is used to feed ammunition into the flywheel to commence firing. Originally, in its stock form, this mechanism depends  on trigger pull by the user to allow ammunition to be fed into the flywheel system. The blaster also no longer requires 6 C batteries as required in its stock formation. Instead, we were able hook the flywheel system, the component that actually fires the ammunition, with a power supply.

At the moment, we have two Arduinos for the blaster, where one operates the servo that feeds ammo into the flywheel system and the other powers the flywheel system.

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

### Frontend Structure:

Being an embedded system project, we do not have a graphical user interface or anything of that sort yet. In its place, we have a rendering of what we envisioned for our implementation at the beginning of the quarter.

<img src="https://github.com/CS178A-B/final-project-sentinals/blob/main/readme_visuals/image6.png" width="300" height="300" />

As of Milestone One, we have two major components in development: the Nerf blaster itself and the base/platform on which the blaster will be mounted on. Below is the dissassembled Nerf blaster with the components needed for it to power ON and fire. We also took away the need for the 6 C batteries needed to power the Blaster and instead attached a Voltage Booster to an AC to DC power supply. Decreasing the overall weight of our Blaster.  

<img src="https://github.com/CS178A-B/final-project-sentinals/blob/main/readme_visuals/NerfBlasterBase.JPG" width="700" height="500"/>

Next, we decided to tackle the Horizontal Movement of the Blaster for Milestone Two. We came up with a few ideas for making the base rotate and finally decided on using ring ball-bearings to assist rotation. A basic servo wouldn't be strong enough to rotate the Blaster efficiently, this is why we decided to attach ball-bearings to assist it. 

We then cut two square pieces of wood that serve as the bread components of a sandwich. We need the boards to sandwich the ball bearings for smooth rotations. 

<img src="https://github.com/CS178A-B/final-project-sentinals/blob/main/readme_visuals/IMG_2266.jpg" width="500" height="500"/>
<center>Eduardo holding what should be the top half of the base on which the blaster will be placed upon</center>

After building the base we attached a small sanded wooden block to it with a glue gun and double sided tape. The wooden block is placed in the middle of one of the bearings. Below are pictures of how the base of the Nerf Blaster looks from the bottom part of its base. 

<img src="https://github.com/CS178A-B/final-project-sentinals/blob/main/readme_visuals/IMG_1617.JPG" width="500" height="500"/>

Next we decided to build the main base which is what the Nerf Sentry will be planted on. The main base will look similar to an open box. The top of this main base is sandwiched with the base of the Nerf Blaster. 

<img src="https://github.com/CS178A-B/final-project-sentinals/blob/main/readme_visuals/NerfSentryFrontJPG.JPG" width="700" height="500"/>

For Milestone Three we organize the components of the Nerf Sentry in a 'nice' fashion so that the wires are not all over the place. The Blaster is able to move Horizontally now and fire upon a moving target!

<img src="https://github.com/CS178A-B/final-project-sentinals/blob/main/readme_visuals/MainBase.JPG" width="700" height="500"/>

## Dependencies
Install Node Package Manager (npm). [Helpful Documentation](https://www.npmjs.com/get-npm)

Pip Install opencv-python [Documentation](https://pypi.org/project/opencv-python/)

arduino-libraries/servo [Repository](https://github.com/arduino-libraries/Servo) 

