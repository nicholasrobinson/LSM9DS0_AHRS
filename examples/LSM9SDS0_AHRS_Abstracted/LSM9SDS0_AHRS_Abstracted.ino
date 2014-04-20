//
//  LSM9SDS0_AHRS_Abstracted.ino
//  LSM9SDS0 AHRS
//
//  Created by Nicholas Robinson on 04/19/14.
//  Copyright (c) 2014 Nicholas Robinson. All rights reserved.
//

#include <SPI.h>
#include <Wire.h>
#include <SFE_LSM9DS0.h>
#include <LSM9DS0_AHRS.h>

LSM9DS0_AHRS* ahrs;

int led = 13;
int count = 0;
int count_delta = 0;

void setup()
{
  Serial.begin(115200);
  pinMode(led, OUTPUT);
  
  ahrs = new LSM9DS0_AHRS(MADGWICK);
}

void loop()
{ 
  ahrs->update();
  
  count_delta = millis() - count;
  if (count_delta < 250)
    digitalWrite(led, HIGH);
  else
    digitalWrite(led, LOW);
    
  if (count_delta > 500) 
  { 
    Serial.print("Yaw, Pitch, Roll: ");
    Serial.print(ahrs->yaw, 2);
    Serial.print(", ");
    Serial.print(ahrs->pitch, 2);
    Serial.print(", ");
    Serial.print(ahrs->roll, 2);
    Serial.print(", dt = "); Serial.println(ahrs->dt, 4);
    count = millis();
  }
}

