#include <IRremote.h>
IRrecv irreceive(11);
decode_results resultsd;
//long int b[]={16230487,16191727,16224367,16208047,16199887,16232527,16216207,16189687,16222327,16206007,16244767,16236607,16203967,4294967295};
//int reset=10;//w
//int opening=11;//on
//int closing=12;//close lock--
//int holdon=13;
//int pw[]={2,0,1,7};
//int type[10];
int t=6;
//int d=5;
int motor1=10;
int motor2=9;
int flag=0;
int btn=0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(motor1,OUTPUT);
pinMode(motor2,OUTPUT);
pinMode(t,OUTPUT);//led is on --open state
//pinMode(d,OUTPUT);
  irreceive.enableIRIn();
}

void loop() {
  // put your main code here, to run repeatedly:
 if (irreceive.decode(&resultsd)) 
 {
      if(btn==0)
    {
      flag=2;
   
       irreceive.resume(); 
    }
    else
      {
      flag=1;
      
    irreceive.resume();
    }
    btn=1-btn;
    Serial.print(btn);
    Serial.print(" ");
    Serial.print(flag);
  
    }
    if(flag==0)
    {digitalWrite(motor1,LOW);
digitalWrite(motor2,LOW);
digitalWrite(t,LOW);
//digitalWrite(d,LOW);}

    if(flag==1)
    {
     digitalWrite(t,HIGH);
      digitalWrite(motor1,HIGH);
digitalWrite(motor2,LOW);
delay(2250);
flag=0;
}

if(flag==2)
{    // digitalWrite(d,HIGH);
  digitalWrite(motor1,LOW);
digitalWrite(motor2,HIGH);
delay(2250);
flag=0;}
    }
