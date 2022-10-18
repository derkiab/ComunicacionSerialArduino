#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

//LiquidCrystal lcd(RS,E,D4,D5,D6,D7);

SoftwareSerial Serial1(10, 11); // RX, TX
LiquidCrystal lcd(2,3,4,5,6,7);
String s1;

void setup()
{
	Serial1.begin(9600);
    Serial.begin(9600);
    lcd.begin(16,2);
}

void loop()
{
  
  if(Serial1.available()>0){
    
  	
    lcd.print("Recibiendo");
    
  	Serial.println("Recibiendo...");
    delay(2000);
    lcd.clear();
    lcd.print("Recibido");
    Serial.println("Recibido :");
    
   	s1 = Serial1.readString();
    delay(200);
    lcd.clear();
    lcd.print(s1);
  	Serial.println(s1);
       
  }
  
  delay(2300);
  lcd.clear();
   
  }
  
  
