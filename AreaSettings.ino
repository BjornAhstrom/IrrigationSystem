void areaSettings() {
  selectedMenu = 18;
  //menuValue = 0;
  insideStartScreen = false;
  tft.fillScreen(GRAY);
  tft.setTextSize(2);
  tft.setCursor(5, 10);
  tft.print("Installningar for omrade ");
  tft.print("1");

  tft.fillRect(20, 28, 280, 2, CYAN);

  writeMenuOptions(selectProgramMenuItems, selectProgramMenuOptions - 1);
  areaMenuSettingsSelection();
}

void areaMenuSettingsSelection() {
  drawMenuSelecting(menuValue, selectProgramMenuOptions - 1);
}

void areaSettingsExecutionAction() {
  
  switch (menuValue) {
    case 0:
      startScreen();
      break;
    case 1:
      break;
    case 2:
      break;
    case 3:
      break;
  }
}
