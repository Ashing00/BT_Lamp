//*****************************************************************************
//BT_Lamp V1.0
//阿布拉機的3D列印與機器人
//http://arbu00.blogspot.tw/
//
//2016/01/10 Writen By Ashing Tsai
//
//
//******************************************************************************
//#include <Timer.h>      
#include <SoftwareSerial.h>
#include <Servo.h> 
Servo servo1;
Servo servo2;
int angle=90;
int angle1=90;
int angle2=90;


#define pinRx 2      
#define pinTx 3  

#define pin4 4      // servo1
#define pin5 5      // servo2

#define pin6 6      
#define pin7 7      
#define pin8 8      
#define pin9 9      

#define pin10 10     
#define pin11 11      
#define pin12 12     
#define pin13 13     
SoftwareSerial BT(pinRx,pinTx);   


String readString;       
char ch;                  
        
void setup() {
  BT.begin(9600);      
  Serial.begin(9600);
  servo1.attach(pin4,500,2500);
  servo1.write(90);                    //middle
  servo2.attach(pin5,500,2500);
  servo2.write(85);                    //middle
    delay(500);

}
void loop() {
  if(readString.length()>0) {  
    readString="";
  }
  while(BT.available()) {  
    delay(2);
    ch = BT.read();
    readString+=ch;
  }
  if (readString=="RO") { 
      	servo1.write(30);    //Hit up site
        delay(300);
        servo1.write(90);
        delay(300);
        

  } else if (readString=="RF") { 

	      servo1.write(150);    //Hit down site
        delay(300);
        servo1.write(90);
        delay(300);
  } else if (readString=="YO") { 
        servo2.write(150);       //Hit up site
        delay(300);
        servo2.write(85);
        delay(300);
  } else if (readString=="YF") { 
        servo2.write(30);      //Hit down site
        delay(300);
        servo2.write(85);
        delay(300);
  } 
}
