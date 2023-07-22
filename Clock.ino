void digitalClockDisplay() {
  tft.setTextColor(WHITE);

  DateTime now = rtc.now();

  oldSecond = seconds;
  oldMinute = minutes;
  oldHour = hours;

  hours = now.hour();
  minutes = now.minute();
  seconds = now.second();

  if (runTimeAndDateOnes) {
    setHours(hours);
    setMinutes(minutes);
    setSeconds(seconds);
    updateDate();

    runTimeAndDateOnes = false;
  }

  if (hours != oldHour) {
    setHours(hours);
    updateDate();
  }

  tft.setTextSize(3);
  tft.setCursor(29, 6);
  tft.println(":");

  if (minutes != oldMinute) {
    setMinutes(minutes);
  }

  tft.setTextSize(3);
  tft.setCursor(64, 6);
  tft.println(":");

  if (seconds != oldSecond) {
    setSeconds(seconds);
  }

}

void setHours(int hour) {
  tft.setTextSize(2);
  if (hour < 10) {
    tft.fillRect(10, 10, 27, 20, GRAY);
    tft.setCursor(10, 10);
    tft.println("0");
    tft.setCursor(22, 10);
    tft.println(hours);
  } else {
    tft.fillRect(10, 10, 27, 20, GRAY);
    tft.setCursor(10, 10);
    tft.println(hours);
  }
}

void setMinutes(int min) {
  tft.setTextSize(2);
  if (min < 10) {
    tft.fillRect(44, 10, 27, 20, GRAY);
    tft.setCursor(44, 10);
    tft.println("0");
    tft.setCursor(57, 10);
    tft.println(minutes);
  } else {
    tft.fillRect(44, 10, 27, 20, GRAY);
    tft.setCursor(44, 10);
    tft.println(minutes);
  }

}

void setSeconds(int sec) {
  tft.setTextSize(2);
  if (sec < 10) {
    tft.fillRect(80, 10, 27, 20, GRAY);
    tft.setCursor(80, 10);
    tft.println("0");
    tft.setCursor(94, 10);
    tft.println(seconds);
  } else {
    tft.fillRect(80, 10, 27, 20, GRAY);
    tft.setCursor(80, 10);
    tft.println(seconds);
  }
}

void updateDate() {
  DateTime now = rtc.now();

  oldYear = year ;
  oldMonth = month;
  oldDay = day;

  year = now.year();
  month = now.month();
  day = now.day();

  tft.fillRect(140, 10, 280, 20, GRAY);

  setYear(year);
  setMonth(month);
  setDay(day);
  setDayName(now);
}

void setYear(int ye) {
  tft.setTextSize(2);
  tft.setCursor(120, 10);
  tft.println(ye);
}

void setMonth(int mon) {
  tft.setTextSize(2);
  if (mon < 10) {
    tft.setCursor(180, 10);
    tft.println("0");
    tft.setCursor(193, 10);
    tft.println(mon);
  } else {
    tft.setCursor(180, 10);
    tft.println(mon);
  }
}

void setDay(int da) {
  tft.setTextSize(2);
  if (da < 10) {
    tft.setCursor(215, 10);
    tft.println("0");
    tft.setCursor(228, 10);
    tft.println(da);
  } else {
    tft.setCursor(215, 10);
    tft.println(da);
  }
}

void setDayName(DateTime now) {
  tft.setTextSize(2);
  tft.setCursor(250, 10);
  tft.println(daysOfTheWeek[now.dayOfTheWeek()]);
}
