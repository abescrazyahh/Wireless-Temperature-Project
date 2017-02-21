void printToLCD()
{
  alarmSet = analogRead(0) / 18;

  Serial.print("***");
  Serial.println(temperature);
  int tmp = atoi(temperature) ;
  Serial.println(tmp);
  float celsius = tmp * 0.0625;
  float fahrenheit = (1.8 * celsius) + 32;
  int f = (int) fahrenheit;
  Serial.println(celsius);
  Serial.println(f);
  //digitalRead(6);             // Reads the value of the pin, like below we are using a boolean
  if (celsius > alarmSet) {
    digitalWrite(6, HIGH);    // This writes a high to a pin or 5v
  }
  else {
    digitalWrite(6, LOW);     // This writes a low to a pin or grounds it
  }

  if (alarmSet == oldAlarm)
  {
    // Display celsius on the top row
    lcd.setCursor(0, 0);
    //1234567890123456 digits for spaces on row
    lcd.print("Temp in C= ");
    lcd.print(celsius);
    // Display fahrenheit to the bottom row
    lcd.setCursor(0, 1);
    //1234567890123456 digits for spaces on row
    lcd.print("Temp in F= ");
    lcd.print(fahrenheit);
    // Turn on the display:
    Serial.println("the Alarm is ");
    Serial.print(alarmSet);
    Serial.println();
  }
  else
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    //1234567890123456 digits for spaces on row
    lcd.print("Alarm temp= ");
    lcd.print(alarmSet);
    // Display fahrenheit to the bottom row
    lcd.setCursor(0, 1);
    //1234567890123456 digits for spaces on row
    lcd.print("  Please wait");

    // Turn on the display:
    Serial.println("The alarm Changed and the display froze");
    Serial.print(alarmSet);
    Serial.println();


    delay(500);
    oldAlarm = alarmSet;

  }
};
