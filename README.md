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
<a href="https://github.com/msalloum" target="_blank"><img src="https://avatars3.githubusercontent.com/u/1790819?s=400&v=4" align="left" height="30px">Mariam Salloum </a>

<a href="https://github.com/eduardor626" target="_blank"><img src="https://avatars1.githubusercontent.com/u/33262466?s=400&u=c6b16422f4524bd8951a4989a7c85fbc6c010f84&v=4" align="left" height="30px">Eduardo Rocha</a>

<a href="https://github.com/B-Tran" target="_blank"><img src="https://avatars0.githubusercontent.com/u/43649007?s=400&v=4" align="left" height="30px">Brandon Tran </a>

<a href="https://github.com/sfazli96" target="_blank"><img src="https://avatars2.githubusercontent.com/u/43709736?s=400&v=4" align="left" height="30px">Sameh Fazli </a>

<a href="https://github.com/LukeTheChang" target="_blank"><img src="https://avatars3.githubusercontent.com/u/43716206?s=400&v=4" align="left" height="30px">Luccas Chang </a>

## Usage
Demo: <Link to youtube video>

<Screenshot of application>

## How To Run
At this moment, two major components are working independently: the openCV facial recognition and the sentry blaster. For facial recognition, an implementation using openCV2 is stored in a Raspberry Pi. The implementation is able to return footage from a webcam connected to the Raspberry Pi where, if a face is recognized, the implementation outlines a rectangle around the face. 

For the sentry blaster, a servo is used to feed ammunition into the flywheel to commence firing. Originally, in its stock form, this mechanism depends  on trigger pull by the user to allow ammunition to be fed into the flywheel system. The blaster also no longer requires 6 C batteries as required in its stock formation. Instead, we were able hook the flywheel system, the component that actually fires the ammunition, with a power supply.

At the moment, we have two Arduinos for the blaster, where one operates the servo that feeds ammo into the flywheel system and the other powers the flywheel system.

In the project directory, you can run:

### `npm start`

Runs the app in the development mode.<br />
Open [http://localhost:3000](http://localhost:3000) to view it in the browser.

The page will reload if you make edits.<br />
You will also see any lint errors in the console.

### `npm test`

Launches the test runner in the interactive watch mode.<br />
See the section about [running tests](https://facebook.github.io/create-react-app/docs/running-tests) for more information.

### `npm run build`

Builds the app for production to the `build` folder.<br />
It correctly bundles React in production mode and optimizes the build for the best performance.

The build is minified and the filenames include the hashes.<br />
Your app is ready to be deployed!

See the section about [deployment](https://facebook.github.io/create-react-app/docs/deployment) for more information.

### `npm run eject`

**Note: this is a one-way operation. Once you `eject`, you can’t go back!**

If you aren’t satisfied with the build tool and configuration choices, you can `eject` at any time. This command will remove the single build dependency from your project.

Instead, it will copy all the configuration files and the transitive dependencies (Webpack, Babel, ESLint, etc) right into your project so you have full control over them. All of the commands except `eject` will still work, but they will point to the copied scripts so you can tweak them. At this point you’re on your own.

You don’t have to ever use `eject`. The curated feature set is suitable for small and middle deployments, and you shouldn’t feel obligated to use this feature. However we understand that this tool wouldn’t be useful if you couldn’t customize it when you are ready for it.

## Diagrams

### Sequence Diagram:

The following two are state machines that we are able to implement to some extent

* State Machine Sensor Controller:

<img src="https://github.com/CS178A-B/final-project-sentinals/blob/main/readme_visuals/image1.jpg" height="300"/>

* State Machine for Raspberry Pi:

<img src="https://github.com/CS178A-B/final-project-sentinals/blob/main/readme_visuals/image3.jpg" height="300"/>

### Frontend Structure:

Being an embedded system project, we do not have a graphical user interface or anything of that sort. In its place, we have a rendering of what we envisioned for our implementation at the beginning of the quarter.

<img src="https://github.com/CS178A-B/final-project-sentinals/blob/main/readme_visuals/image6.png" width="300" height="300"/>

### Overall System Diagram:

<img src="https://github.com/CS178A-B/final-project-sentinals/blob/main/readme_visuals/image4.jpg" width="500" height="500"/>

## Dependencies
Install Node Package Manager (npm). [Helpful Documentation](https://www.npmjs.com/get-npm)

Pip Install opencv-python [Documentation](https://pypi.org/project/opencv-python/)

arduino-libraries/servo [Repository](https://github.com/arduino-libraries/Servo) //not sure if correct api

