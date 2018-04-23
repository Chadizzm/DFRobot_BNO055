/*
 * file AbsoluteAccelerationDemo.ino
 *
 * @ https://github.com/DFRobot/DFRobot_BNO055
 *
 * connect BNO055 I2C interface with your board (please reference board compatibility)
 *
 * Uses last loaded QuaData and LinAccData and prints it out through the serial port.
 *
 * Copyright   [DFRobot](http://www.dfrobot.com), 2016
 * Copyright   GNU Lesser General Public License
 *
 * version  V0.1
 * date  2018-1-8
 */
 
#include <Wire.h> 
#include "DFRobot_BNO055.h"

DFRobot_BNO055 mpu;

void setup() 
{
   Serial.begin(115200);
   while (!mpu.init())
   {
     Serial.println("ERROR! Unable to initialize the chip!");
     delay(50);
   }
//   mpu.setMode(mpu.eNORMAL_POWER_MODE, mpu.eFASTEST_MODE);
   delay(100);
   Serial.println("Calculate absolute acceleration...");
}

void loop() 
{
  mpu.calcAbsLinAcc(); /* calculate absolute acceleration */
  
  Serial.print("X: "); 
  Serial.print(mpu.AbsLinAccData.x, 3); 
  Serial.print(" m/s^2   ");
  Serial.print("Y: "); 
  Serial.print(mpu.AbsLinAccData.y, 3); 
  Serial.print(" m/s^2   ");
  Serial.print("Z: "); 
  Serial.print(mpu.AbsLinAccData.z, 3); 
  Serial.println(" m/s^2   ");
  delay(200);
}

