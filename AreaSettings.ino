void areaSettings(int selectBoxIndex) {
  selectedMenu = 18;
  //menuValue = 0;
  insideStartScreen = false;
  tft.fillScreen(GRAY);
  tft.setTextColor(BLACK);
  tft.setTextSize(2);
  tft.setCursor(30, 10);
  tft.print("Omrade ");
  tft.print(areaViews[selectBoxIndex].areaViewName);

  Serial.print("selectBoxIndex: ");
  Serial.println(selectBoxIndex);

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
      programSettings(1);
      break;
    case 2:
      programSettings(2);
      break;
    case 3:
      programSettings(3);
      break;
  }
}
