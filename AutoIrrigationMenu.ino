void autoIrrigationMenu() {
  selectedMenu = 3;
  menuValue = 0;

  tft.fillScreen(GRAY);
  tft.setTextSize(2);
  tft.setCursor(35, 10);
  tft.println("Automatisk bevattning");
  tft.fillRect(20, 28, 280, 2, MAGENTA);
  
  writeMenuOptions(autoIrrigationMenuItems, autoMenuOptions - 1);
  autoIrrigationMenuSelection();
}

void autoIrrigationMenuSelection() {
  drawMenuSelecting(menuValue, autoMenuOptions - 1);
}

void autoIrrigationExecuteAction() {

  switch (menuValue) {
    case 0:
      mainMenu();
      break;
    case 1:
      Serial.println("Auto bevattning");
      schedulingIrrigation();
      break;
    case 2:

      Serial.println("Full auto");
      //fullAutoIrrigation();
      break;
  }
}
