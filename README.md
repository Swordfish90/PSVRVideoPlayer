# PSVRVideoPlayer

A simple 360° 3D video player for your PSVR.

It's a funny weekend project, still in early stages, that should work on all major
OSs.

The only dependencies are Qt >= 5.7 and libusb, and uses the awesome libpsvr to handle
the low level communication.

Tested on Ubuntu 16.04 with Qt 5.8 (snapshot).

## What's in here
* 3D Stereo Video player
* Headset orientation tracking with sensor fusion
* Lens correction shaders
* Dumb CLI interface

## What's missing
* A cool stereoscopic interface
* Lenses chromatic distortions
* Support for other video formats (180° and standard 360°)
* Support for pictures
* ???


## How to use it

Please keep in mind that this project is till in early stages so don't expect smooth sail.

* Build PSVRVideoPlayer from source (no packages yet)
* Connect your PSVR headset to your PC (both HDMI and USB) and make it mirror your screen
* Run the application from command line passing a 360 3D stereo video file as first argument

Controls:
* Space -> Play/Pause
* Backspace -> Restore headset position
* Left/Right -> Seek -15/+15 seconds
* Escape -> Close PSVRVideoPlayer

## Want to help?

Suggestions and contributions are always welcome.
