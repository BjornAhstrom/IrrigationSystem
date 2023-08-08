void programSettings(int program) {
  selectedMenu = 4;
  menuValue = 0;

  tft.fillScreen(GRAY);
  tft.setTextSize(2);
  tft.setCursor(108, 10);
  tft.print("Program ");
  tft.println(program);
  tft.fillRect(20, 28, 280, 2, CYAN);
  setStartHourAction();

  setTimeToStartIrrigation();


}

void setTimeToStartIrrigation() {
  menuValue = startHour;

  startTimerClockIcon(10, 40, BLACK, GRAY);

  showHours(startHour, 65, 49);
  tft.setCursor(105, 49);
  tft.println(":");
  showMinutes(startMinute, 125, 49);
}

void setStartHourAction() {
  menuValue = startHour;
  setStartHour = true;
}

void setStartMinuteAction() {
  startHour = menuValue;
  menuValue = startMinute;
  selectedMenu = 5;
  showHours(startHour, 65, 49);
  setStartHour = false;
  setStartMinute = true;
}

void setIrrigationTimeTimer() {
  setStartMinute = false;
  showMinutes(startMinute, 125, 49);
  startMinute = menuValue;
  menuValue = timerHour;
  selectedMenu = 6;

  setTimeTimerHour = true;

  hourglassIcon(10, 85, BLACK, GRAY);
  showHours(timerHour, 65, 94);
  tft.setTextSize(2);
  tft.setCursor(105, 100);
  tft.print("tim");
}

void setTimerMinute() {
  timerHour = menuValue;
  menuValue = timerMinute;
  selectedMenu = 7;
  setTimeTimerHour = false;
  setTimeTimerMinute = true;
  showHours(timerHour, 65, 94);

  showMinutes(timerMinute, 150, 94);
  tft.setTextSize(2);
  tft.setCursor(193, 100);
  tft.print("min");

}

void saveTimerData() {
  setTimeTimerMinute = false;

  setHumidityPercentMinAndMax();
}

void setHumidityPercentMinAndMax() {
  showMinutes(timerMinute, 150, 94);
  selectedMenu = 8;
  menuValue = minPercent;
  waterDropIcon(10, 130, 8, BLACK);
  startMinPercentBlinking = true;
  showMinPercent(minPercent, 65, 139);
  tft.setTextSize(2);
  tft.setCursor(125, 145);
  tft.print("%");
  tft.setCursor(139, 145);
  tft.print("min");
}

void saveHumidityMinPercent() {
  startMinPercentBlinking = false;
  startMaxPercentBlinking = true;
  minPercent = menuValue;
  selectedMenu = 9;

  showMinPercent(minPercent, 65, 139);
  showMaxPercent(maxPercent, 180, 139);
  tft.setTextSize(2);
  tft.setCursor(240, 145);
  tft.print("%");
  tft.setCursor(254, 145);
  tft.print("max");
}

void saveHumidityMaxPercent() {
  startMaxPercentBlinking = false;
  maxPercent = menuValue;
  showMaxPercent(maxPercent, 180, 139);
  setDaysToIrrigate();
}

void setDaysToIrrigate() {


  calendarIcon(10, 175, BLACK, GRAY);
  tft.setTextSize(2);
  tft.setCursor(62, 184);
  tft.println("Mo Tu We Th Fr Sa Su");
}

/*void programSettings(int program) {
  selectedMenu = 17;
  menuValue = 0;

  tft.fillScreen(GRAY);
  tft.setTextSize(2);
  tft.setCursor(108, 10);
  tft.print("Program ");
  tft.println(program);
  tft.fillRect(20, 28, 280, 2, MAGENTA);

  SetSchedulingTime();
  }*/

/*void SetSchedulingTime() {
  setTimeToStartIrrigation();
  setIrrigationTimer();
  setHumidityPrecent();
  nextButton();
  }

  void setTimeToStartIrrigation() {
  startTimerClockIcon(20, 50, BLACK, GRAY);
  tft.setTextSize(3);
  tft.setCursor(75, 59);
  tft.println("05:35");
  }

  void setIrrigationTimer() {
  hourglassIcon(20, 100, BLACK, GRAY);
  tft.setTextSize(3);
  tft.setCursor(75, 109);
  tft.print("9");
  tft.setTextSize(2);
  tft.setCursor(97, 115);
  tft.println("tim");
  tft.setTextSize(3);
  tft.setCursor(155, 109);
  tft.println("35");
  tft.setTextSize(2);
  tft.setCursor(197, 115);
  tft.println("min");
  }

  void setHumidityPrecent() {
  waterDropIcon(20, 150, 8, BLACK);
  tft.setTextSize(3);
  tft.setCursor(75, 159);
  tft.print("40");
  tft.setCursor(120, 159);
  tft.print("%");
  tft.setCursor(155, 159);
  tft.print("-");
  tft.setCursor(190, 159);
  tft.print("60");
  tft.setCursor(235, 159);
  tft.print("%");
  }

  void nextButton() {
  tft.fillRoundRect(80, 213, 160, 25, 3, BLACK);
  tft.setTextColor(GRAY);
  tft.setTextSize(2);
  tft.setCursor(131, 217);
  tft.println("Nasta");
  }*/



void startSetStartHourToBlink() {

  if (setStartHour) {
    if (millis() - runTime >= 500) {
      runTime = millis();

      if (startHourBlinking) {
        showHours(startHour, 65, 49);
      } else {
        hideHours(64, 48);
      }
      startHourBlinking = !startHourBlinking;
    }
  }
}



void startSetStartMinuteToBlink() {

  if (setStartMinute) {
    if (millis() - runTime >= 500) {
      runTime = millis();

      if (startMinuteBlinking) {
        showMinutes(startMinute, 125, 49);
      } else {
        hideMinutes(124, 48);
      }
      startMinuteBlinking = !startMinuteBlinking;
    }
  }
}

void startSetTimeTimerHourToBlink() {

  if (setTimeTimerHour) {
    if (millis() - runTime >= 500) {
      runTime = millis();

      if (startHourBlinking) {
        showHours(startHour, 65, 94);
      } else {
        hideHours(64, 93);
      }
      startHourBlinking = !startHourBlinking;
    }
  }
}

void startSetTimeTimerMinuteToBlink() {
  if (setTimeTimerMinute) {
    if (millis() - runTime >= 500) {
      runTime = millis();

      if (startMinuteBlinking) {
        showMinutes(startMinute, 150, 94);
      } else {
        hideMinutes(149, 93);
      }
      startMinuteBlinking = !startMinuteBlinking;
    }
  }
}

void startMinPercentToBlink() {
  if (startMinPercentBlinking) {
    if (millis() - runTime >= 500) {
      runTime = millis();

      if (blinkingHumidityPercent) {
        showMinPercent(minPercent, 65, 139);
      } else {
        hideMinPercent(64, 138);
      }
      blinkingHumidityPercent = !blinkingHumidityPercent;
    }
  }
}

void startMaxPercentToBlink() {
  if (startMaxPercentBlinking) {
    if (millis() - runTime >= 500) {
      runTime = millis();

      if (blinkingHumidityPercent) {
        showMaxPercent(maxPercent, 180, 139);
      } else {
        hideMaxPercent(180, 138);
      }
      blinkingHumidityPercent = !blinkingHumidityPercent;
    }
  }
}



void showMinPercent(int percent, int y, int x) {
  minPercent = percent;
  tft.setTextSize(3);
  /*if (percent < 10) {
    tft.fillRect(y - 1, x - 1, 62, 22, GRAY);
    tft.setTextColor(BLACK);
    tft.setCursor(y, x);
    tft.println("00");
    tft.setCursor(y + 36, x);
    tft.println(percent);
  }
  else*/ if (percent < 10) {
    tft.fillRect(y - 1, x - 1, 62, 22, GRAY);
    tft.setTextColor(BLACK);
    tft.setCursor(y, x);
    tft.println("0");
    tft.setCursor(y + 20, x);
    tft.println(percent);
  }
  else {
    tft.fillRect(y - 1, x - 1, 62, 22, GRAY);
    tft.setTextColor(BLACK);
    tft.setCursor(y, x);
    tft.println(percent);
  }
}

void showMaxPercent(int percent, int y, int x) {
  maxPercent = percent;
  tft.setTextSize(3);
  /*if (percent < 10) {
    tft.fillRect(y - 1, x - 1, 62, 22, GRAY);
    tft.setTextColor(BLACK);
    tft.setCursor(y, x);
    tft.println("00");
    tft.setCursor(y + 36, x);
    tft.println(percent);
  } else*/ if (percent < 10) {
     tft.fillRect(y - 1, x - 1, 62, 22, GRAY);
    tft.setTextColor(BLACK);
    tft.setCursor(y, x);
    tft.println("0");
    tft.setCursor(y + 20, x);
    tft.println(percent);
  }
  else {
    tft.fillRect(y - 1, x - 1, 42, 22, GRAY);
    tft.setTextColor(BLACK);
    tft.setCursor(y, x);
    tft.println(percent);
  }
}





void hideMinPercent(int y, int x) {
  tft.fillRect(y, x, 52, 22, GRAY);
}

void hideMaxPercent(int y, int x) {
  tft.fillRect(y, x, 53, 22, GRAY);
}

void showHours(int hours, int y, int x) {
  startHour = hours;
  tft.setTextSize(3);
  if (hours < 10) {
    tft.fillRect(y - 1, x - 1, 42, 22, GRAY);
    tft.setTextColor(BLACK);
    tft.setCursor(y, x);
    tft.println("0");
    tft.setCursor(y + 20, x);
    tft.println(hours);
  } else {
    tft.fillRect(y - 1, x - 1, 42, 22, GRAY);
    tft.setTextColor(BLACK);
    tft.setCursor(y, x);
    tft.println(hours);
  }
}

void hideHours(int y, int x) {
  tft.fillRect(y, x, 42, 22, GRAY);
}

void showMinutes(int minutes, int y, int x) {
  startMinute = minutes;

  tft.setTextSize(3);
  if (minutes < 10) {
    tft.fillRect(y - 1, x - 1, 42, 22, GRAY);
    tft.setTextColor(BLACK);
    tft.setCursor(y, x);
    tft.println("0");
    tft.setCursor(y + 20, x);
    tft.println(minutes);
  } else {
    tft.fillRect(y - 1, x - 1, 42, 22, GRAY);
    tft.setTextColor(BLACK);
    tft.setCursor(y, x);
    tft.println(minutes);
  }
}

void hideMinutes(int y, int x) {
  tft.fillRect(y, x, 42, 22, GRAY);
}
