# Overview
Dodecahedron keyboard is a three-dimensional USB keyboard.

We can type With the Dodecahedron keyboard very efficiently.

This project is based on [rv003usb](https://github.com/cnlohr/rv003usb)

# Hardware
Connect key switches and pins for WCH-LinkE (writer) to UIAPduino.

<img src="/images/controller-circuit.png" height="400px">

# 3D Model

# Building the Firmware
## Prerequisites
This project uses [ch32fun](https://github.com/cnlohr/ch32fun) (SDK) and WCH-LinkE (writer).

Please install the required tools in [this page](https://github.com/cnlohr/ch32fun/wiki/Installation) beforehand.

## Repository
Clone this project and initialize submodules with the following command.

```
git submodule update --init --recursive
```
## Build and Flash
Connect your WCH-LinkE to your PC and the UIAPduino pins (5V/GND/SWIO) then run the following commands.
```
cd src
make
make flash
```
