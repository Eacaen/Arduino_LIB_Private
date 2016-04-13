#include <MsTimer2.h>




//Timer_learn.ino
// 利用  mills（）同样函数可以实现中断的功能。mills()函数功能是获取系统运行的时间长度
// 单位ms。最大为9小时22分，如果超出时间将从0开始。函数的返回值为unsigned long型。

// PS：使用mills（）函数的好处在于占用的整个程序运行时间短，
// 如果用用延时函数，在延时的时间内，CPU不能干别的事儿。

unsigned long ledOn=500,ledOff=500; //定义led灯变化的时间长度，每500ms变化一次
int ledStatus;                      //定义LED灯的状态，HIGH or LOWm 
void setup()
{
    pinMode(13,OUTPUT);
    digitalWrite(13,HIGH);
    ledStatus=HIGH;
}
void loop()
{
    unsigned long nowtime=millis(); //获取当前的系统运行时间长度
    if(ledStatus==HIGH)             //如果当前lled灯状态为高电平，则执行该程序
    {
      if(nowtime>ledOn)             //检测系统运行时间长度是否到500ms
      {
        ledOn=nowtime;              //记录当前时间长度，第一次为500ms,赋值给ledOn
        ledOff=nowtime+500;         //计算出下一次led灯变化的时刻，第一次运行程序时应该在1000ms时关灯
        digitalWrite(13,LOW);       //关掉led灯
        ledStatus=LOW;              //记录当前led灯状态，下一次使用     
      } 
    }
 
  else{       
         if(nowtime>ledOff)
         {   
          ledOff=nowtime;
          ledOn=nowtime+500;
          digitalWrite(13,HIGH);
          ledStatus=HIGH;
         }
      }
}
