void loop() {
  checkRotaryEncoderStatus();
  startSetStartHourToBlink();
  startSetStartMinuteToBlink();
  startSetTimeTimerHourToBlink();
  startSetTimeTimerMinuteToBlink();
  startMinPercentToBlink();
  startMaxPercentToBlink();
  /*startBlinkingTime();
    startBlinkingHour();
    startBlinkingMinute();
    startBlinkingDate();
    startBlinkingYear();
    startBlinkingMonth();
    startBlinkingDay();
    activatIrrigationBlinkingTime();
    activateBlinkingIrrigationHour();
    activateBlinkingIrrigationMinute();*/

  if (!insideMenu && !insideAreaSettings) {
    digitalClockDisplay();
  }

  unsigned long currentMillis = millis();
  // Kolla om intervallet har passerat
  if (currentMillis - previousMillis >= interval) {
    // Spara nuvarande tid som senaste tidpunkt
    previousMillis = currentMillis;
    displayStartAndIrrigationTime(selectBoxIndex, currentIndex);
    currentIndex = (currentIndex + 1) % textCount;
  }

}


void menuBtnPress() {
  openMainMenu = false;
  if (!digitalRead(sw) == HIGH) {
    //insideStartScreen = false;
    //insideMenu = true;
    //mainMenu();

    delay(100);
    while (!digitalRead(sw));
  }
}

void mainMenuBtnPress() {
  if (!digitalRead(sw) == HIGH) {

    delay(100);
    while (!digitalRead(sw));
  }
}
