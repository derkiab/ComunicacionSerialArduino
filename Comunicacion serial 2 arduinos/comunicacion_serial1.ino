#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

//LiquidCrystal lcd(RS,E,D4,D5,D6,D7);
SoftwareSerial Serial1(10, 11); // RX, TX
LiquidCrystal lcd(2,3,4,5,6,7);
int opcion;
String s1;

void setup()
{
  Serial1.begin(9600);
  Serial.begin(9600);
  lcd.begin(16,2);
  randomSeed(analogRead(0));

}

void loop()
{
  lcd.clear();
  Serial.println("1. Enviar Caracter");
  Serial.println("2. Enviar String");
  Serial.println("3. Enviar Valores aleatorios");
  while (Serial.available() == 0) {}
  
  
 opcion = Serial.parseInt();
  
  if(opcion == 1){
   
    Serial.println("Por favor, Ingrese el caracter a enviar");
    while (Serial.available() == 0) {}
    
    s1 = Serial.readString();
    
    Serial.println("Enviando el caracter :");
    Serial.println(s1);
    char array[s1.length()];
    s1.toCharArray(array,2);
    lcd.print("Enviando...");
    delay(4000);
    Serial1.write(array,2);
    lcd.clear();
    lcd.print("Enviado");
    Serial.println("Enviado");
    delay(1000);
    lcd.clear();
    lcd.print(s1);
    delay(1000);
  }
  
  if(opcion == 2){
    
    Serial.println("Por favor, Ingrese el string a enviar");
    while(Serial.available() ==0){}
   
    String s1 = Serial.readString();
    Serial.println("Enviando el String :");
    Serial.println(s1);
    char array[s1.length()];
    s1.toCharArray(array,s1.length()+1);
    lcd.print("Enviando...");
    delay(4000);
    Serial1.write(array,s1.length()+1);
    lcd.clear();
    lcd.print("Enviado");
    Serial.println("Enviado");
    delay(1000);
    lcd.clear();
    lcd.print(s1);
    delay(1000);
    
    
  }
  
  if(opcion == 3){

    lcd.clear();
    Serial.println("Eligiendo numero al azar");
    int x;
    x=random(1,6);
    char array[x];
	String s2;
    
    for(int i=0;i<x;i++){
		
      	int r;
        r = random(0,9); 
		s2 += r;
    }
		
    	Serial.println(s2);
    	s2.toCharArray(array,x+1);
        delay(2000);
        lcd.clear();
        lcd.print("Enviando...");
        Serial.println("Enviando...");
        delay(4000);
        Serial1.write(array,x+1);
        lcd.clear();
        lcd.print("Enviado");
        Serial.println("Enviado");
        delay(2000);
    	lcd.clear();
    	lcd.print(s2);
    	delay(3000);

  }
}

