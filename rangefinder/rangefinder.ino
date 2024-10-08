#define trigPin 12
#define echoPin 8
#define buzzer 10

//Flashing LED on Arduino board
#define LEDPin 13

//Include the required libraries for LCD
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Define I2C Address
// Find the I2C Address by running the sketch_oct16a12caddress.ino file in the directory 
// Make sure you connect your I2C module( in this case LCD module) before running the address code
#define I2C_ADDR  0x27  
#define BACKLIGHT_PIN   3
#define En_pin  2
#define Rw_pin  1
#define Rs_pin  0
#define D4_pin  4
#define D5_pin  5
#define D6_pin  6
#define D7_pin  7

int n = 1;

LiquidCrystal_I2C     lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);


void setup ()
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);  //The transmit pin of the ultrasonic sensor
  pinMode(echoPin, INPUT);   //The receive pin of the ultrasonic sensor
  pinMode(LEDPin, OUTPUT);   //The LED of the Arduino
  pinMode(buzzer,OUTPUT);

  lcd.begin (20,4);  //Size of LCD
 
// Switch on the backlight
  lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
  lcd.setBacklight(HIGH);
  lcd.home ();                // go home

}

void loop()
{
  int duration, distance;
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(100);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance =(duration/2) / 29.1;

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Distance from OB");
  lcd.setCursor(0,1);
  lcd.print(distance);
  lcd.print("cm");
  if (distance >=10)
  {
    lcd.setCursor(0,4);
    lcd.print("Safe Zone :)");
    digitalWrite(LEDPin,HIGH);
      delay(500);
      digitalWrite(LEDPin,LOW);
      delay(500);
   
  }
    else
  {   tone(buzzer,2000);
      delay(1000);
      noTone(buzzer);
      delay(100);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(" STEP AWAY!!!");
      lcd.setCursor(0,1);
      lcd.print(" STEP AWAY!!!");
      lcd.setCursor(0,2);
      lcd.print(" STEP AWAY!!!");
      lcd.setCursor(0,3);
      lcd.print(" STEP AWAY!!!");
      digitalWrite(LEDPin,HIGH);
      delay(50);
      digitalWrite(LEDPin,LOW);
      delay(50);
      digitalWrite(LEDPin,HIGH);
      delay(50);
      digitalWrite(LEDPin,LOW);
      delay(50);
      digitalWrite(LEDPin,HIGH);
      delay(50);
      digitalWrite(LEDPin,LOW);
      delay(50);
      digitalWrite(LEDPin,HIGH);
      delay(50);
      digitalWrite(LEDPin,LOW);
      delay(50);
      digitalWrite(LEDPin,HIGH);
      delay(50);
      digitalWrite(LEDPin,LOW);
      delay(50);
      digitalWrite(LEDPin,HIGH);
      delay(50);
      digitalWrite(LEDPin,LOW);
      delay(50);
      digitalWrite(LEDPin,HIGH);
      delay(50);
      digitalWrite(LEDPin,LOW);
      delay(50);
      digitalWrite(LEDPin,HIGH);
      delay(50);
      digitalWrite(LEDPin,LOW);
      delay(50);
      digitalWrite(LEDPin,HIGH);
      delay(50);
      digitalWrite(LEDPin,LOW);
      delay(50);
      digitalWrite(LEDPin,HIGH);
      delay(50);
      digitalWrite(LEDPin,LOW);
      delay(50);
      digitalWrite(LEDPin,HIGH);
      delay(50);
      digitalWrite(LEDPin,LOW);
      

  }

}
