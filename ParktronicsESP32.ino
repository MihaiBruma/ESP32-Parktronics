#include <Adafruit_GFX.h>
#include <LiquidCrystal.h>
#include <Wire.h>

//Preprocessor
#define trigger_pin 12
#define Echo_pin 14
#define SOUND_VELOCITY 0.034
#define CM_TO_INCH 0.393701
#define RS 13
#define En 27
#define D4 32
#define D5 33
#define D6 25
#define D7 26
#define LED1Pin 22 // red right
#define LED2Pin 23
#define LED3Pin 5
#define LED4Pin 2 // red left
#define LED5Pin 21
#define LED6Pin 19
#define Buzzer 4


long duration;
int32_t distance;

LiquidCrystal My_LCD(RS, En, D4, D5, D6, D7);

void setup() {

pinMode(LED1Pin, OUTPUT);
pinMode(LED2Pin, OUTPUT);
pinMode(LED3Pin, OUTPUT);
pinMode(LED4Pin, OUTPUT);
pinMode(LED5Pin, OUTPUT);
pinMode(LED6Pin, OUTPUT);
pinMode(Buzzer, OUTPUT);

My_LCD.begin(16, 2);
My_LCD.clear();
pinMode(trigger_pin, OUTPUT); 
pinMode(Echo_pin, INPUT); 
Serial.begin(9600); 
}

void loop() {

digitalWrite(Buzzer, LOW);
delay(1000);
digitalWrite(trigger_pin, LOW); 
delayMicroseconds(2);

digitalWrite(trigger_pin, HIGH);  
delayMicroseconds(10);           
digitalWrite(trigger_pin, LOW);   

duration = pulseIn(Echo_pin, HIGH);
distance = (duration/2) / 29 ;
 if ( distance <= 75 )
  {
    digitalWrite(LED3Pin, HIGH);
    digitalWrite(LED6Pin, HIGH);
    My_LCD.setCursor(0,0);
    My_LCD.print(">");
    My_LCD.setCursor(15,0);
    My_LCD.print("<");
    My_LCD.setCursor(0,1);
    My_LCD.print("(!)SURROUNDINGS");

  }
  else
  {
    digitalWrite(LED3Pin, LOW);
    digitalWrite(LED6Pin, LOW);
    My_LCD.setCursor(0,0);
    My_LCD.print(" ");
    My_LCD.setCursor(15,0);
    My_LCD.print(" ");
    My_LCD.setCursor(0,1);
    My_LCD.print("               ");
  }
  if ( distance <= 50 )
  {
    digitalWrite(LED2Pin, HIGH);
    digitalWrite(LED5Pin, HIGH);
    My_LCD.setCursor(2,0);
    My_LCD.print(">>>");
    My_LCD.setCursor(13,0);
    My_LCD.print("<");
    My_LCD.setCursor(12,0);
    My_LCD.print("<");
    My_LCD.setCursor(11,0);
    My_LCD.print("<");
  }
  else
  {
    digitalWrite(LED2Pin, LOW);
    digitalWrite(LED5Pin, LOW);
    My_LCD.setCursor(2,0);
    My_LCD.print("   ");
    My_LCD.setCursor(13,0);
    My_LCD.print(" ");
    My_LCD.setCursor(12,0);
    My_LCD.print(" ");
    My_LCD.setCursor(11,0);
    My_LCD.print(" ");
  }
  if ( distance <= 25 )
  {
    digitalWrite(LED1Pin, HIGH);
    digitalWrite(LED4Pin, HIGH);
    My_LCD.setCursor(6,0);
    My_LCD.print("STOP");
    digitalWrite(Buzzer, HIGH);
  }
  else
  {
    digitalWrite(LED1Pin, LOW);
    digitalWrite(LED4Pin, LOW);
    My_LCD.setCursor(6,0);
    My_LCD.print("    ");
    digitalWrite(Buzzer, LOW);
  }

Serial.print("Distance: ");
Serial.println(distance);
}
