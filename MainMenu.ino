void mainMenu() {
  insideStartScreen = false;
  selectedMenu = 0;
  menuValue = 0;
  tft.fillScreen(GRAY);
  tft.setTextSize(2);
  tft.setCursor(120, 10);
  tft.println("Meny");
  tft.fillRect(20, 28, 280, 2, MAGENTA);

  writeMenuOptions(mainMenuItems, mainMenuOptions - 1);
  mainMenuSelection();
}

void mainMenuSelection() {
  drawMenuSelecting(menuValue, mainMenuOptions - 1);
}

void mainMenuExecutionAction() {
  switch (menuValue) {
    case 0:
      startScreen();
      break;
    case 1:
      autoIrrigationMenu();
      break;
    case 2:
      manuallIrrigationMenu();
      break;
    case 3:
      Serial.println("Datum och tid");
      adjustTimeAndDate();
      break;
    case 4:
      Serial.println("Installningar");
      settings();
      break;
  }
}
