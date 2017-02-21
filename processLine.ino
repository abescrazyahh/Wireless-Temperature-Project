void processLine(char *s)
{
  int number = 0;
  Serial.print(num++);
  Serial.print(" ");
  Serial.println(s);

  char *f;
  char buffer[100];
  char *t = buffer;
  strcpy(t, s);

  Serial.print("* ");
  Serial.println(t);

  for (;;)
  {
    f = strsep(&t, ",");
    if (f == NULL)
    {
      Serial.println("f==NULL");
      break;
    }
    else
    {
      if (number == 0)
      {
        strcpy(temperature, f);
      }
      /* else if (number == 1)
        {
         strcpy(humidity, f);                     More sensors
        }
      */
      //  Serial.print(number++);
      //  Serial.print(" ");
      //  Serial.println(f);
    }

  }
}
