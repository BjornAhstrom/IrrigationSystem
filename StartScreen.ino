void startScreen() {
  insideMenu = false;
  insideStartScreen = true;
  runTimeAndDateOnes = true;
  
  tft.fillScreen(GRAY);
  tft.setTextSize(3);

  tft.fillRect(0, 32, 320, 2, BLACK);
  displayProgram();

  tft.fillRect(0, 83, 320, 2, BLACK);

  startTimerClockIcon(10, 88);
  hourglassIcon(10, 130);

  hourglassIcon(10, 172);

  tft.setTextColor(BLACK);
  tft.setTextSize(2);
  tft.setCursor(55, 180);
  tft.println("Mo Tu We Th Fr Sa Su");

}
