void programSettings(int boxIndex, int program) {
  selectedMenu = 4;
  menuValue = 0;
  
  Serial.print("Box: ");
  Serial.println(boxIndex);
  Serial.print("Program: ");
  Serial.println(program);
  
  selectBoxIndex = boxIndex;
  selectProgramIndex = program;

  tft.fillScreen(GRAY);
  tft.setTextSize(2);
  tft.setCursor(108, 10);
  tft.print("Program ");
  tft.println(program);
  tft.fillRect(20, 28, 280, 2, CYAN);

  splitMilliseconds(areaViews[boxIndex].programAreas[program].lenghtOfIrrigation, timerHour, timerMinute);
  
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
  menuValue = areaViews[selectBoxIndex].programAreas[selectProgramIndex].startTime.hour(); 
  startTimerClockIcon(10, 40, 41, BLACK, GRAY);
  setStartHour = true;
}

void setStartMinuteAction() {
  setStartHour = false;
  startHour = menuValue;

  selectedMenu = 5;
  menuValue = areaViews[selectBoxIndex].programAreas[selectProgramIndex].startTime.minute();
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
  saveButton();
}

void saveButton() {
  blinkingSaveBtn = true;
  selectedMenu = 19;
  startSaveBtnToBlink();
  
}

void startSaveBtnToBlink() {

  if (blinkingSaveBtn) {
    if (millis() - runTime >= 500) {
      runTime = millis();

      if (startBlinkingBtn) {
        showSaveBtn();
      } else {
        hideSaveBtn();
      }
      startBlinkingBtn = !startBlinkingBtn;
    }
  }
}

void showSaveBtn() {
  tft.fillRect(85, 210, 150, 30, BLACK);
  tft.setTextSize(2);
  tft.setCursor(130, 220);
  tft.setTextColor(WHITE);
  tft.print("Spara");
}

void hideSaveBtn() {
  tft.fillRect(85, 210, 150, 30, LIGHTGRAY);
  tft.setTextSize(2);
  tft.setCursor(130, 220);
  tft.setTextColor(WHITE);
  tft.print("Spara");
}


/*void setHumidityPercentMinAndMax() {
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
  //setDaysToIrrigate();
}
*/


long convertToMilliseconds(int hours, int minutes) {
  return (hours * 3600000) + (minutes * 60000);
}

void saveIrrigationData() {
  blinkingSaveBtn = false;
  // Saving data
  areaViews[selectBoxIndex].programAreas[selectProgramIndex].startTime = DateTime(0, 0, 0, startHour, startMinute, 0);
  areaViews[selectBoxIndex].programAreas[selectProgramIndex].lenghtOfIrrigation = convertToMilliseconds(timerHour, timerMinute);
  

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
