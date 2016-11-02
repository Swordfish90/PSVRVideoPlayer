#LibPSVR
C library for Morpheus (Playstation VR). Tested with Ubuntu 15.10 + libusb-1.0.20.

## Build
```
$ ./build.sh
```
## Example
```
$ gcc example.c -I/path_to_psvr_h -L/path_to_libpsvr_so -lpsvr
```
## OS X (El Capitan)
For quick start, use brew before build.  

```
$ brew install pkg-config libusb
```

You will need to unload kernel modules manually.  

```
$ sudo kextunload -b com.apple.driver.usb.IOUSBHostHIDDevice
```
