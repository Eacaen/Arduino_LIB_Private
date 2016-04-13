

//serial_state.ino

int led = 13;  
int i = 0;
  
unsigned char data[10];
enum STATE
{
	rep1,rep2,rep3,rep4,rep5
};
 STATE Serial_State = rep1;
void setup() {
   
  
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  Serial.begin(9600);
 
}

void LED_Shark()
{
	digitalWrite(led, HIGH);  // turn the LED on (HIGH is the voltage level)
    delay(1000);               // wait for a second
    digitalWrite(led, LOW);   // turn the LED off by making the voltage LOW
    delay(1000);               // wait for a second
}

void loop() 
{
	
	//LED_Shark();
  
  // put your main code here, to run repeatedly:
    while(Serial.available()>0)
    {
      delay(10);
    	data[i]=Serial.read();
      Serial.print(i);Serial.println(  data[i]);
    	i++;
    }
    i=0;

switch (Serial_State)
{
     case rep1:
    	if(data[0] == 0xff)
    	{
    		Serial_State = rep2;

        Serial.println(Serial_State);
    		Serial.println("enter 1");
    	}
     else
     {
      Serial_State = rep1;
      memset(data,0,sizeof(data));
      }
    	break;
    case rep2:
    	if(data[1] == 0xff)
    	{
    		Serial_State = rep3;
			Serial.println("enter 2");
      Serial.println(Serial_State);
    	}
       else
     {
      Serial_State = rep1;
      memset(data,0,sizeof(data));
      }
    	break;
    case rep3:
    	if(data[2] == 0xff)
    	{
    		Serial_State = rep4;
			Serial.println("enter 3");
      Serial.println(Serial_State);
    	}
       else
     {
      Serial_State = rep1;
      memset(data,0,sizeof(data));
      }
    	break;
    case rep4:
    	if(data[3] == 0xff)
    	{
    		Serial_State = rep5;
			Serial.println("enter 4");
      Serial.println(Serial_State);
    	}
       else
     {
      Serial_State = rep1;
      memset(data,0,sizeof(data));
      }
    	break;
    case rep5:
    	if(data[4] == 0xff)
    	{
    		Serial_State = rep1;
			Serial.println("enter 5");
			Serial.println(Serial_State);
     memset(data,0,sizeof(data));
			LED_Shark();
    	}
       else
     {
      Serial_State = rep1;
      memset(data,0,sizeof(data));
      }
    	break;
dafault:
      Serial_State = rep1;
       memset(data,0,sizeof(data));
}
}
