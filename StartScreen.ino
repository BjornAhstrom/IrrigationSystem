void startScreen() {
  openMainMenu = false;
  insideMenu = false;
  insideStartScreen = true;
  runTimeAndDateOnes = true;
  
  tft.fillScreen(GRAY);
  tft.setTextSize(3);

  tft.fillRect(0, 32, 320, 2, BLACK);
  displayProgram();

  tft.fillRect(0, 83, 320, 2, BLACK);


  areaView();
}
