#include <Wire.h>
 
#include <arduino_mpu6050.h>

// MPU6050 MPU6050;

short  Acceleration[3];
short AX,AY,AZ;
short Temperature;


void MPU6050::IIC_WriteOneByte(unsigned char add,unsigned char reg,unsigned char para)
{
	Wire.beginTransmission(add); //开启MPU6050的传输
    Wire.write(reg); //指定寄存器地址
    Wire.write(para); //写入一个字s节的数据
    Wire.endTransmission(true); //结束传输，true表示释放总线
}

unsigned char MPU6050::IIC_Read_Single(unsigned char add,unsigned char reg )
{
	Wire.beginTransmission(add); //开启MPU6050的传输
    Wire.write(reg); //指定寄存器地址
    Wire.requestFrom(add, 1, true); //将输据读出到缓存
    Wire.endTransmission(true); //关闭传输模式
    return Wire.read();
}
  

void MPU6050::IIC_Init()
{
	Wire.begin();            //设置I2通信时的本机地址
 	// Wire.beginTransmission(SlaveAddress);//启动I2通信,读取MPU6050地址
// Wire.write(GYRO_CONFIG);//从传感器写入数据
// Wire.write(ACCEL_CONFIG);
//	Wire.write(8);          //写入8位字节
	Wire.endTransmission();//结束通信
}

  
void MPU6050::InitMPU6050()
{
	
  int i=0,j=0;
   for(i=0;i<1000;i++)
  {
    for(j=0;j<1000;j++)
    {
      ;
    }
  }
	IIC_WriteOneByte(SlaveAddress, PWR_MGMT_1, 0x00);		//解除休眠状态
	IIC_WriteOneByte(SlaveAddress,SMPLRT_DIV, 0x07);		//陀螺仪采样率，典型值：0x07(125Hz)
	IIC_WriteOneByte(SlaveAddress,MPU_CONFIG, 0x06);	//低通滤波频率，典型值：0x06(5Hz)
	IIC_WriteOneByte(SlaveAddress,GYRO_CONFIG, 0x18);		//陀螺仪自检及测量范围，典型值：0x18(不自检，2000deg/s)
	IIC_WriteOneByte(SlaveAddress,ACCEL_CONFIG, 0x00);	//加速计自检、测量范围及高通滤波频率，典型值：0x01(不自检，2G，5Hz)
}


int MPU6050::MPU6050ReadID(void)
{
	unsigned char Re = 0;
	// Wire.write(WHO_AM_I); //指定寄存器地址
 //    Wire.requestFrom(add, 1, true); //将输据读出到缓存
 //    Wire.endTransmission(true); //关闭传输模式
    Re = IIC_Read_Single(SlaveAddress,WHO_AM_I );    
    return Re;
}


int MPU6050::CombineData(unsigned char REG_Address)
{
	short H=0,L=0;
	short ComNum;
	H = IIC_Read_Single(SlaveAddress, REG_Address );
	L = IIC_Read_Single(SlaveAddress, REG_Address+1 );
	ComNum = (H<<8) | L;
	return  ComNum; // 
}

void MPU6050::Calibration()
{
	static int i=0;
	
}

void MPU6050::GetData()
{
	short temp3;
	 Acceleration[0]=CombineData(ACCEL_XOUT_H);
	 Acceleration[1]=CombineData(ACCEL_YOUT_H);	
	 Acceleration[2]=CombineData(ACCEL_ZOUT_H);	
	
	AX = CombineData(GYRO_XOUT_H);
	AY = CombineData(GYRO_YOUT_H);
	AZ = CombineData(GYRO_ZOUT_H);
	
// 	temp3=CombineData(TEMP_OUT_H);
// 	Temperature=(((double) (temp3 + 13200)) / 280)-13.0;
	
}

void MPU6050::Data_Trans(Acce acc,Gyro gyro)
{
// 	acc.x=(double)(Acceleration[0]*9.8/16384);
// 	acc.y=(double)(Acceleration[1]*9.8/16384);	
// 	acc.z=(double)(Acceleration[2]*9.8/16384);	
	
	acc.x=(double)(Acceleration[0]);
	acc.y=(double)(Acceleration[1]);	
	acc.z=(double)(Acceleration[2]);	
	gyro.x=(double)(AX/16.4);
	gyro.y=(double)(AY/16.4);
	gyro.z=(double)(AZ/16.4);
}



void MPU6050::Data_Pare(Acce acc,Gyro gyro)
{
	// static int i=0;
	// if(i==0)
	// {
	// 	Calibration();
	// }
	// i=1;
	GetData();
	Data_Trans(acc,gyro);
}



