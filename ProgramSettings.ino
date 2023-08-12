void programSettings(int program) {
  selectedMenu = 4;
  menuValue = 0;

  tft.fillScreen(GRAY);
  tft.setTextSize(2);
  tft.setCursor(108, 10);
  tft.print("Program ");
  tft.println(program);
  tft.fillRect(20, 28, 280, 2, CYAN);
  
  setTimeToStartIrrigation();
}

void setTimeToStartIrrigation() {


  showHours(startHour, 65, 49);
  tft.setCursor(105, 49);
  tft.println(":");
  showMinutes(startMinute, 125, 49);

  setStartHourAction();
}

void setStartHourAction() {
  menuValue = startHour;
  startTimerClockIcon(10, 40, 41, BLACK, GRAY);
  setStartHour = true;
}

void setStartMinuteAction() {
  setStartHour = false;
  startHour = menuValue;

  selectedMenu = 5;
  menuValue = startMinute;
  setStartMinute = true;
  showHours(startHour, 65, 49);
}

void setIrrigationTimeTimer() {
  setStartMinute = false;
  startMinute = menuValue;
  showMinutes(startMinute, 125, 49);

  selectedMenu = 6;
  menuValue = timerHour;
  setTimeTimerHour = true;

  hourglassIcon(10, 85, BLACK, GRAY);
  showHours(timerHour, 65, 94);
  tft.setTextSize(2);
  tft.setCursor(105, 100);
  tft.print("tim");
}

void setTimerMinute() {
  timerHour = menuValue;
  selectedMenu = 7;
  menuValue = timerMinute;
  setTimeTimerHour = false;
  setTimeTimerMinute = true;
  showHours(timerHour, 65, 94);

  showMinutes(timerMinute, 150, 94);
  tft.setTextSize(2);
  tft.setCursor(193, 100);
  tft.print("min");

}

void saveTimerData() {
  timerMinute = menuValue;
  setTimeTimerMinute = false;
  showMinutes(timerMinute, 150, 94);
  setHumidityPercentMinAndMax();
}

void setHumidityPercentMinAndMax() {
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
  selectedMenu = 10;
  menuValue = 0;

  calendarIcon(10, 175, BLACK, GRAY);
  tft.setTextSize(2);
  tft.setCursor(62, 184);
  tft.println("Mo Tu We Th Fr Sa Su");
  chooseDay(menuValue);

  tft.fillRoundRect(90, 219, 140, 19, 5, BLACK);
  tft.setTextSize(2);
  tft.setTextColor(GRAY);
  tft.setCursor(130, 221);
  tft.print("Spara");
}

void chooseDay(int value) {
  int totalPadding = 305 - 62 - 7 * 25 + 10; // Total padding between boxes
  int padding = totalPadding / (7); // Padding between each box

  // Draw the gray lines for all days first
  for (int i = 0; i < 7; i++) {
    int grayX = 50 + padding * (i + 1) + i * 25;
    tft.fillRect(grayX, 210, 25, 2, GRAY);

    if (areaViews[0].programAreas[0].daysToTurnOn.days[i]) {
      tft.fillRect(grayX, 210, 25, 2, BLACK);
    }
  }

  if (value <= 6) {
    // Draw the black line for the selected day
    int x = 50 + padding * (value + 1) + value * 25; // Calculate X position for selected box
    tft.fillRect(x, 210, 25, 2, BLACK);
    tft.setTextSize(2);
    tft.setTextColor(GRAY);
    tft.setCursor(130, 221);
    tft.print("Spara");

    if (areaViews[0].programAreas[0].daysToTurnOn.days[value]) {
      tft.fillRect(x, 210, 25, 2, WHITE);
    }
  }
  else if (value == 7) {
    //tft.fillRoundRect(90, 219, 140, 19, 5, BLACK);
    tft.setTextSize(2);
    tft.setTextColor(WHITE);
    tft.setCursor(130, 221);
    tft.print("Spara");
  }
}

void selectDay() {
  areaViews[0].programAreas[0].daysToTurnOn.days[menuValue] = !areaViews[0].programAreas[0].daysToTurnOn.days[menuValue];
  chooseDay(menuValue);
}

long convertToMilliseconds(int hours, int minutes) {
  return (hours * 3600000) + (minutes * 60000);
}

void saveIrrigationData() {
  // Saving data
  areaViews[0].programAreas[0].startTime = DateTime(0, 0, 0, startHour, startMinute, 0);
  areaViews[0].programAreas[0].lenghtOfIrrigation = convertToMilliseconds(timerHour, timerMinute);
  areaViews[0].programAreas[0].soilmoistureValueMin = minPercent;
  areaViews[0].programAreas[0].soilmoistureValueMax = maxPercent;

  if (millis() - runTime >= 200) {
    runTime = millis();
    startScreen();
  }

}

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
        showHours(timerHour, 65, 94);
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
        showMinutes(timerMinute, 150, 94);
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
  //startHour = hours;
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
  //startMinute = minutes;

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
