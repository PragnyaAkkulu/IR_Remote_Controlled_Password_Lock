#include <IRremote.h>
IRrecv irreceive(11);
decode_results resultsd;

//these values depend on the remote that you are using
long long int b[]={1328228931,3020061475,3823372655,4088376079,3064608687,3867919867,3128236099,3372243203,4175554383,2490970248,00000,1611541999,2738032675,00000};
int reset=10;//w
int opening=11;//on
int closing=12;//close lock--
int holdon=13;
int led=6;
int pw=2019; //password :)
int type;
int motor1=10;
int motor2=9;
int flag=0;//action happening on lock ->opening/closing/no action
int v=0;//status of lock: closed->0, open->1
 void typing(int t);
 void check(int *type);

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(motor1,OUTPUT);
pinMode(motor2,OUTPUT);
pinMode(led,OUTPUT);
  irreceive.enableIRIn();
}

void loop() {
  // put your main code here, to run repeatedly:
 if (irreceive.decode(&resultsd)) 
    {
              
                    if(resultsd.value==b[0])
                    {typing(0);}
                    else if(resultsd.value==b[1])
                    {typing(1);}
                    else if(resultsd.value==b[2])
                    {typing(2);}
                    else if(resultsd.value==b[3])
                    {typing(3);}
                    else if(resultsd.value==b[4])
                    {typing(4);}
                    else if(resultsd.value==b[5])
                    {typing(5);}
                    else if(resultsd.value==b[6])
                    {typing(6);}
                    else if(resultsd.value==b[7])
                    {typing(7);}
                    else if(resultsd.value==b[8])
                    {typing(8);}
                    else if(resultsd.value==b[9])
                    {typing(9);}
                    else if(resultsd.value==b[opening])
                    {typing(11);  
                    }
                    else if(resultsd.value==b[closing])
                    {if(v==1)
                    {flag=2;
                    v=0;}
                    }
                       
      irreceive.resume();
    }
       if(flag==0)//no action
    {digitalWrite(motor1,LOW);
digitalWrite(motor2,LOW);}

    if(flag==1)//opening
    {
      digitalWrite(led,HIGH);
      delay(250);
      digitalWrite(led,LOW);
    
      digitalWrite(motor1,HIGH);
digitalWrite(motor2,LOW);
delay(2200);
flag=0;
Serial.print("opened");
Serial.print(v);}

if(flag==2)//closing
{digitalWrite(motor1,LOW);
digitalWrite(motor2,HIGH);
delay(2200);
flag=0;
Serial.print("closed");
Serial.print(v);}
    }
    //------------------------------------------------------------
     
//-------------------------------------------------------
    void typing(int t)
{ static int f=0;
  if(t==11)
check(&f);
   
  else if(t<10 && t>=0)
    f=(f*10)+t;
      // Serial.print(f);
  }
  //-----------------------------------------------------------------------------
  void check(int *type)
  {
    Serial.print(*type);
    if (*type==pw)
    {flag=1;
    v=1;}
    else
    flag=*type=0;
    }
