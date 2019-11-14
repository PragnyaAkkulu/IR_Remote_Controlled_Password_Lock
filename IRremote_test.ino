#include <IRremote.h>
#include <IRremoteInt.h>
#include <IRremoteTools.h>
int rec=3//pin3 analog
void setup() 
{
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop()
{
  //press the buttons of your IR remote to see their corresponding values on the serial monitor
Serial.println(analogRead(rec));
}
