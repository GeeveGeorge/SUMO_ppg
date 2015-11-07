/*
 * Smart Pulse Monitor 
 * Author : Geeve George
 * Instrubtables : http://www.instructables.com/member/Geeve+George/
 */
 
 
#include <Wire.h>

const int analogInPin = A0;  


int sensorValue = 0;       

int count=0;
unsigned long time1=0;  
unsigned long time2;    


#include "rgb_lcd.h"

rgb_lcd lcd;

const int colorR = 255;
const int colorG = 0;
const int colorB = 0;

void setup() {
 
  Serial.begin(9600); 
 
  lcd.begin(16, 2);
    
    lcd.setRGB(colorR, colorG, colorB);
}

void loop() {

  
  
  
  if(count==0)
  {time1=millis();
  }
  time2=millis();
  sensorValue = analogRead(analogInPin);
  
     
    
    
    
 
  if(time2>=time1+10000)
  { counter();
  }
  

  if(sensorValue <500){
    
    lcd.clear();
    
    Serial.println("Insert finger");
    lcd.setCursor(0,0);
    lcd.print("Insert Finger");
  
   
    return;
 }
                       
       
      

  
  if(sensorValue >500){
    
    lcd.clear();
  digitalWrite(Led, HIGH);
    increment();

  Serial.println(sensorValue);
 Serial.println(count);
 Serial.println(time2);
 lcd.setCursor(0,0);
 lcd.print("Counting");
    
  }
  
 
 delay(200);
    
  }

void increment()
{
  count++;

} 

    void counter()
{ 
  lcd.clear();
  count=count*6;
  Serial.print("Heart beat: ");
  Serial.print(count);
  lcd.setCursor(0,0);
  lcd.print("Heart beat:");
  lcd.setCursor(0,1);
  lcd.print(count);
  lcd.print(" BPM");
  
  
  time1=0;
  time2=0;
  count=0;
  
 delay(5000);
    

  
 
}
