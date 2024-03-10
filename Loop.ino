void loop() {
  checkRotaryEncoderStatus();
  startSetStartHourToBlink();
  startSetStartMinuteToBlink();
  startSetTimeTimerHourToBlink();
  startSetTimeTimerMinuteToBlink();
  startMinPercentToBlink();
  startMaxPercentToBlink();
  startSaveBtnToBlink();
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

  if (!insideMenu && !insideAreaSettings && !menuView) {
    digitalClockDisplay();

    for (int i = 0; i < amountOfArea; i++) {

      //for (int j = 0; j < 3; j++) {
        if (areaViews[i].programAreas[0].startTime.hour() != 0 && areaViews[i].programAreas[0].startTime.minute() != 0 || timerMinute != 0 && timerHour != 0) {
          unsigned long currentMillis = millis();
          // Kolla om intervallet har passerat
          if (currentMillis - previousMillis >= interval) {
            // Spara nuvarande tid som senaste tidpunkt
            previousMillis = currentMillis;
            displayStartAndIrrigationTime(selectBoxIndex, currentIndex);
            Serial.print("currentIndex: ");
            Serial.println(currentIndex);

            tft.fillRect(277, 99, 20, 25, GRAY);
            tft.setTextSize(3);
            tft.setTextColor(BLACK);
            tft.setCursor(278, 100);
            tft.print(currentIndex + 1);

            currentIndex = (currentIndex+1) % textCount;
          //}
        }
      }
    }
  } else if (runStartScreenOnce && !insideMenu && !insideAreaSettings) {
      Serial.println("Displaying startScreen");
      areaView();
      runStartScreenOnce = false;
  }

  // for (int i = 0; i < numRelays; i++) {
  //   digitalWrite(relays[i], ON);
  //   delay(500);
  //   digitalWrite(relays[i], OFF);
  // }
}


/*void menuBtnPress() {
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
}*/
