#include <LiquidCrystal.h>
#include <Wire.h>
#include <string.h>
float oldAlarm;
int pos = 0;
char buffer[100];
int num = 0;
char temperature[50];
char humidity[50];
float alarmSet = 0;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);   // initialize the library with the numbers of the interface pins
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(6, OUTPUT);
  delay(500);
  lcd.begin(16, 2);
  lcd.display();
  // set up the LCD's number of columns and rows:
}
void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0)
  {
    int reading = Serial.read();         // read it and store it in 'val'
    if ( reading == '\r' )
    {
      //nothing
    }
    else if ( reading == '\n' )
    {
      buffer[pos] = '\0';
      pos = 0;
      processLine(buffer);
      printToLCD();
    }
    else
    {
      buffer[pos] = reading;
      pos++;
    }
  }
};





