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

  if (!insideMenu) {
    digitalClockDisplay();
    menuBtnPress();
  }

}


void menuBtnPress() {

  if (!digitalRead(sw) == HIGH) {
    insideStartScreen = false;
    insideMenu = true;
    mainMenu();
    delay(100);
    while (!digitalRead(sw));
  }
}
