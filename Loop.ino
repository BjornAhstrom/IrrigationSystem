void loop() {
  checkRotaryEncoderStatus();

  startBlinkingTime();
  startBlinkingHour();
  startBlinkingMinute();
  startBlinkingDate();
  startBlinkingYear();
  startBlinkingMonth();
  startBlinkingDay();
  activatIrrigationBlinkingTime();
  activateBlinkingIrrigationHour();
  activateBlinkingIrrigationMinute();

  if (!insideMenu && !insideAreaSettings) {
    digitalClockDisplay();
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
