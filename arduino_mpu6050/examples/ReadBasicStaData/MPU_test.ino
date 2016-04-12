#include <arduino_mpu6050.h>
#include <Wire.h>

extern short  Acceleration[3];
extern short AX,AY,AZ;
MPU6050 mpu6050;
Acce acc;
Gyro gyro;
int temp;
// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  mpu6050.IIC_Init();
   mpu6050.InitMPU6050();  
}

// the loop function runs over and over again forever
void loop() {  
 // temp = mpu6050.MPU6050ReadID();
 // Serial.print("ID ");Serial.println(temp);
//  acc.x = mpu6050.MPU_Read(ACCEL_XOUT_H);Serial.print(acc.x);Serial.print(" ");
//  acc.y = mpu6050.MPU_Read(ACCEL_YOUT_H);Serial.print(acc.y);Serial.print(" "); 
//  acc.z = mpu6050.MPU_Read(ACCEL_ZOUT_H);Serial.print(acc.z);Serial.print(" ");  
 

  gyro.y = mpu6050.MPU_Read(GYRO_YOUT_H);Serial.print(gyro.y);Serial.print(" "); 
  gyro.z = mpu6050.MPU_Read(GYRO_ZOUT_H);Serial.print(gyro.z);Serial.print(" ");  
  gyro.x = mpu6050.MPU_Read(GYRO_XOUT_H);Serial.print(gyro.x);Serial.print(" "); 
  
	Serial.println( );
	
 	
 	

}


