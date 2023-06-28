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
  }
}
