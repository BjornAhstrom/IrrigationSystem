void digitalClockDisplay() {
  if (oldSecond != second()) {
    hoursToUpdate();
    minutesToUpdate();
    secondsToUpdate();
    //yearToUpdate();
    monthToUpdate();
    dayToUpdate();
    weekDay();
    oldSecond = second();
  }
}

void weekDay() {
  lcd.setCursor(9, 0);
  lcd.print(daysOfTheWeek[weekday() - 1]);
}

void yearToUpdate() {
  lcd.setCursor(0, 1);
  lcd.print(year());
  lcd.setCursor(4, 1);
  lcd.print("/");
}

void monthToUpdate() {
  if (month() < 10) {
    lcd.setCursor(17, 0);
    lcd.print("0");
    lcd.setCursor(18, 0);
    lcd.print(month());
  } else {
    lcd.setCursor(17, 0);
    lcd.print(month());
  }
}

void dayToUpdate() {
  if (day() < 10) {
    lcd.setCursor(14, 0);
    lcd.print("0");
    lcd.setCursor(15, 0);
    lcd.print(day());
  } else {
    lcd.setCursor(14, 0);
    lcd.print(day());
  }
  lcd.setCursor(16, 0);
  lcd.print("/");
}

void hoursToUpdate() {

  if (hour() < 10) {
    lcd.setCursor(0, 0);
    lcd.print("0");
    lcd.setCursor(1, 0);
    lcd.print(hour());
  } else {
    lcd.setCursor(0, 0);
    lcd.print(hour());
  }
  lcd.setCursor(2, 0);
  lcd.print(":");
}

void minutesToUpdate() {

  if (minute() < 10) {
    lcd.setCursor(3, 0);
    lcd.print("0");
    lcd.setCursor(4, 0);
    lcd.print(minute());
  } else {
    lcd.setCursor(3, 0);
    lcd.print(minute());
  }
  lcd.setCursor(5, 0);
  lcd.print(":");
}

void secondsToUpdate() {

  if (second() < 10) {
    lcd.setCursor(6, 0);
    lcd.print("0");
    lcd.setCursor(7, 0);
    lcd.print(second());
  } else {
    lcd.setCursor(6, 0);
    lcd.print(second());
  }
}
