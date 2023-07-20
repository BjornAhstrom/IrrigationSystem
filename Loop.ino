void loop() {
  checkRotaryEncoderStatus();
  menuBtnPress();
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
  }
  
}


void menuBtnPress() {

  if (!digitalRead(sw) == HIGH) {
    //insideMenu = 1;
    mainMenu();
    Serial.println("BUTTON PRESS!!!");
    delay(100);
    while (!digitalRead(sw));
  }
}
