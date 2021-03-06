/*
 * file LinearAccelerationDemo.ino
 *
 * @ https://github.com/DFRobot/DFRobot_BNO055
 *
 * connect BNO055 I2C interface with your board (please reference board compatibility)
 *
 * Gets the current linear acceleration of the sensor and prints it out through the serial port.
 *
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
   Serial.println("Read linear acceleration...");
}

void loop() 
{
  mpu.readLinAcc();   /* read linear acceleration */
  Serial.print("X: "); 
  Serial.print(mpu.LinAccData.x,3); 
  Serial.print(" m/s^2  ");
  Serial.print("Y: "); 
  Serial.print(mpu.LinAccData.y,3); 
  Serial.print(" m/s^2  ");
  Serial.print("Z: "); 
  Serial.print(mpu.LinAccData.z,3); 
  Serial.println(" m/s^2  ");
  delay(200);
}

