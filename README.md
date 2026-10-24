# Overview
The Dodecahedron keyboard is an experimental three-dimensional USB keyboard with an unusual layout.

The Dodecahedron keyboard is ergonomically designed and allows you to type efficiently.

This project is based on [rv003usb](https://github.com/cnlohr/rv003usb)

[![The world cheapest DIY Leverless](https://markdown-videos-api.jorgenkh.no/url?url=https%3A%2F%2Fyoutu.be%2F7mj5RYsmdnM)](https://youtu.be/7mj5RYsmdnM) <img src="/images/dodecahedron-keyboard-photo.jpg" height="180px">

# Hardware
Connect the key switches and pins for WCH-LinkE (writer) to the UIAPduino.

<img src="/images/controller-circuit.png" height="400px">

# 3D Model
The 3D models are available on [Thingiverse](https://www.thingiverse.com/thing:7426392)

# Building the Firmware
## Prerequisites
This project uses [ch32fun SDK](https://github.com/cnlohr/ch32fun) and WCH-LinkE programmer.

Install the required tools by following the instructions on [this page](https://github.com/cnlohr/ch32fun/wiki/Installation).

## Repository
Clone this repository and initialize submodules using the following commands.

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

## How to use
Connect the Dodecahedron Keyboard to your PC using a USB-C cable, then press keys to start typing.
