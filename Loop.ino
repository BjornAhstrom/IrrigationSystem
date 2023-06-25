void loop() {
  checkRotaryEncoderStatus();
  startBlinkingTime();
  startBlinkingHour();
  startBlinkingMinute();
  startBlinkingDate();
  startBlinkingYear();
  startBlinkingMonth();
  startBlinkingDay();

  if (!insideMenu) {
    digitalClockDisplay();
  }
}
