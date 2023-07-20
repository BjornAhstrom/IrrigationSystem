
void RTCSetup() {
 
  if (! rtc.begin())
  {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    abort();
  }
  
  Serial.println("Setting the time...");
  // Ställ in rätt tid på RTC-modulen (endast första gången eller om batteriet är borttaget)
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__))); // Använd detta för att ställa in tiden enligt datorns klocka
  // rtc.adjust(DateTime(2022, 08, 27, 4, 0, 0));

  scheduledTime = DateTime(0, 0, 0, startHour, startMinute, 0); // Ange önskad tid utan att ange datum
}

void updateDate() {
  DateTime now = rtc.now();
  oldDay = day;

  year = now.year();
  month = now.month();
  day = now.day();

  

  //if(day != oldDay) {
  // Date
  //lcd.clear();
  /*lcd.setCursor(0, 0);
  lcd.print("Dat: ");
  lcd.setCursor(5, 0);
  lcd.print(year, DEC);
  lcd.setCursor(9, 0);
  lcd.print("/");
  lcd.setCursor(10, 0);
  lcd.print(month, DEC);
  lcd.setCursor(11, 0);
  lcd.print("/");
  lcd.setCursor(12, 0);
  lcd.print(day, DEC);
  lcd.setCursor(14, 0);
  lcd.print(" ");*/
  //}
}

void updatTime() {

  DateTime now = rtc.now();
  oldSecond = 0;

  hours = now.hour();
  minutes = now.minute();
  seconds = now.second();

  if (seconds != oldSecond) {

    // Weekday
    //lcd.setCursor(15, 0);
    //lcd.print("     ");
    //lcd.setCursor(15, 0);
    //lcd.print(daysOfTheWeek[now.dayOfTheWeek()]);
  
    //Time
    //lcd.setCursor(0, 1);
    //lcd.print("Tid: ");
    setHours(hours);
    //lcd.setCursor(7, 1);
    //lcd.print(":");
    setMinutes(minutes);
    //lcd.setCursor(10, 1);
    //lcd.print(":");
    setSeconds(seconds);
    updateDate();
  }
}
void setHours(int hour) {
  if (hour < 10) {
    /*lcd.setCursor(5, 1);
    lcd.print("  ");
    lcd.setCursor(5, 1);
    lcd.print("0");
    lcd.setCursor(6, 1);
    lcd.print(hours, DEC);*/
  } else {
    /*lcd.setCursor(5, 1);
    lcd.print("  ");
    lcd.setCursor(5, 1);
    lcd.print(hours, DEC);*/
  }
}

void setMinutes(int min) {
  if (min < 10) {
    /*lcd.setCursor(8, 1);
    lcd.print(" ");
    lcd.setCursor(8, 1);
    lcd.print("0");
    lcd.setCursor(9, 1);
    lcd.print(minutes, DEC);*/
  } else {
   /* lcd.setCursor(8, 1);
    lcd.print(" ");
    lcd.setCursor(8, 1);
    lcd.print(minutes, DEC);*/
  }

}

void setSeconds(int sec) {
  if (sec < 10) {
    /*lcd.setCursor(13, 1);
    lcd.print("       ");
    lcd.setCursor(11, 1);
    lcd.print("  ");
    lcd.setCursor(11, 1);
    lcd.print("0");
    lcd.setCursor(12, 1);
    lcd.print(seconds, DEC);*/
  } else {
    /*lcd.setCursor(13, 1);
    lcd.print("       ");
    lcd.setCursor(11, 1);
    lcd.print("  ");
    lcd.setCursor(11, 1);
    lcd.print(seconds, DEC);*/
  }
}
