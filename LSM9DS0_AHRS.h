//
//  LSM9SDS0_AHRS.h
//  LSM9SDS0 AHRS
//
//  Created by Nicholas Robinson on 04/19/14.
//  Copyright (c) 2014 Nicholas Robinson. All rights reserved.
//

#ifndef __LSM9DS0_AHRS_H__
#define __LSM9DS0_AHRS_H__

#include <SFE_LSM9DS0.h>

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
  #include "pins_arduino.h"
#endif

#define LSM9DS0_XM  0x1D
#define LSM9DS0_G   0x6B

// Madgwick Constants
#define GyroMeasError PI * (40.0f / 180.0f)
#define beta sqrt(3.0f / 4.0f) * GyroMeasError

// Mahony Constants
#define Kp 2.0f * 5.0f
#define Ki 0.0f

enum UpdateMethod
{
	MAHONY = 0,
	MADGWICK = 1
};

class LSM9DS0_AHRS
{
	public:
		LSM9DS0_AHRS(UpdateMethod updateMethod);
		void update();
		
		float pitch, yaw, roll;
		float ax, ay, az, gx, gy, gz, mx, my, mz;
		float q[4];
		float dt;
	
	private:
		LSM9DS0* initializeMarg();
		void readMarg();
		void updateQuaternions();
		void updateEulerAngles();
		void tick();
		void madgwickQuaternionUpdate(float ax, float ay, float az, float gx, float gy, float gz, float mx, float my, float mz);
		void mahonyQuaternionUpdate(float ax, float ay, float az, float gx, float gy, float gz, float mx, float my, float mz);
		
		LSM9DS0* marg;
		UpdateMethod updateMethod;
		float mahonyErrors[3];
		uint16_t lastUpdate;
};

#endif // __LSM9DS0_AHRS_H__