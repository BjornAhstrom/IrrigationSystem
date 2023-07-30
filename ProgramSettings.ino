void programSettings(int program) {
  selectedMenu = 17;
  menuValue = 0;

  tft.fillScreen(GRAY);
  tft.setTextSize(2);
  tft.setCursor(108, 10);
  tft.print("Program ");
  tft.println(program);
  tft.fillRect(20, 28, 280, 2, CYAN);
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
}

void SetSchedulingTime() {
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
