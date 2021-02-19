/*
   FROM
  
      STUPIDCREATIVITY
     CODE BY DIVIJ VIGNESH
*/
     
     
#include <Wire.h>
#include <LiquidCrystal_I2C.h> //LCD display library
#define BACKLIGHT_PIN     13  
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); //Address of LCD display
#include<SoftwareSerial.h>
#define TxD 3 
#define RxD 2 
#define LED_PIN 13
SoftwareSerial bluetoothSerial(TxD,RxD);
char c;
void setup() 
{
  bluetoothSerial.begin(9600);
  lcd.begin(20,4);    
  Serial.begin(9600);
}

void loop() 
{
 
 if(bluetoothSerial.available()>0)
 {
  c=bluetoothSerial.read();
  
  lcd.print(c); 
  if(c=='|') //Clears the screen if '|' is entered
 {
 lcd.clear();
 }
   Serial.print(c);
 } 
}
