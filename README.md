# LSM9DS0 AHRS Driver for Arduino

by Nicholas Robinson

## Overview

An AHRS driver leveraging the LSM9DS0 library and AHRS example code from sparkfun (https://github.com/sparkfun/LSM9DS0_Breakout).

The LSM9DS0 iNEMO inertial module features a 3D digital linear acceleration sensor, and a 3D digital angular rate sensor, a 3D digital magnetic sensor. This driver allows simple access to AHRS yaw, pitch and roll calculated using Sebastian Madgwick and Robert Mayhony’s orientation filters.

## Usage

```html
#include <SFE_LSM9DS0.h>
#include <LSM9DS0_AHRS.h>

LSM9DS0_AHRS* ahrs;

void setup()
{ 
  ahrs = new LSM9DS0_AHRS(MADGWICK);
  // Can also be invoked:
  // ahrs = new LSM9DS0_AHRS(MAHONY);
}

void loop()
{ 
  ahrs->update();
  
  // YOUR_STUFF
  // raw, pitch and roll available with:
  // ahrs->yaw, ahrs->pitch and ahrs->roll
}
```

## Requirements

* Arduino compatible board
* LSM9DS0 iNEMO inertial module
* Logic level converter (if necessary)
* SFE_LSM9DS0 library from sparkfun (https://github.com/sparkfun/LSM9DS0_Breakout)

## Tested On

Arduino R3 (https://www.sparkfun.com/products/11021), with:
* LSM9DS0 IMU Breakout - 9DoF (https://www.sparkfun.com/products/12636)
* PCA9306 Level Translator Breakout (https://www.sparkfun.com/products/11955)