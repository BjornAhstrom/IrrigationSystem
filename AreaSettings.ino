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
      setSoilmoistureValue();
      break;
    case 2:
      setDaysToIrrigate();
      break;
    case 3:
      programSettings(selectBoxIndex, 0);
      break;
    case 4:
      programSettings(selectBoxIndex, 1);
      break;
    case 5:
      programSettings(selectBoxIndex, 2);
      break;

  }
}
