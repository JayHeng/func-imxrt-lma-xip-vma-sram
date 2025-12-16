# MCUXpresso SDK : mcux-edgelock

## Overview
This repository is for MCUXpresso SDK EdgeLock firmware delivery and it contains
the components officially provided in NXP MCUXpresso SDK. This repository is
part of the MCUXpresso SDK overall delivery which is composed of several
sub-repositories/projects. Navigate to the top/parent repository
(mcuxsdk-manifests) for the complete delivery of MCUXpresso SDK.

## Documentation
Overall details can be reviewed here: [MCUXpresso SDK Online Documentation](https://mcuxpresso.nxp.com/mcuxsdk/latest/html/introduction/README.html)

## Setup
Instructions on how to install the MCUXpresso SDK provided from GitHub via
west manifest [Getting Started with SDK - Detailed Installation Instructions](https://mcuxpresso.nxp.com/mcuxsdk/latest/html/gsd/installation.html#installation)

## Contribution
Contributions are not currently accepted.
Guidelines to contribute will be posted in the future.

---------------------------------

## Using the Firmware
This repository contains precompiled loadable firmware for various EdgeLock
enclaves. The firmware files are provided in binary format and are
intended to be loaded into memory alongside the application binary.

Some devices are capable of loading such firmware during runtime.
For demonstration purposes, all SDK examples that utilize runtime-loadable
firmwares use a C-array representation of the corresponding firmware binary.

Loading the firmwares is done by using the provided APIs for each of such
systems' messaging units:
* S200: `ELEMU_loadFw()`,
* S400: `ELE_LoadFw()`.

Enclaves without the runtime firmware loading capability:
* ELE_HSEB.

### Python script for binary file conversion
A simple Python script is provided as part of this repository. It can be used
for replicating the firmware loading flow shown in the SDK examples for
devices with the runtime loading capability.

The script `convert_binary_to_c_header.py` takes one positional argument,
which is a path to the firmware binary that's to be converted to a C header.
The resulting C header file will contain an array of `const uint8_t` values,
containing the entire input firmware file.

The output file (named `edgelock_firmware.h`) is created in
the same directory, from which the script is run.

Usage:
```
python convert_binary_to_c_header.py [-h|--help] FIRMWARE_BINARY_FILE
```
