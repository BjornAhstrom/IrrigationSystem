void schedulingIrrigation() {
  selectedMenu = 13;
  menuValue = 0;

  tft.fillScreen(GRAY);
  tft.setTextSize(2);
  tft.setCursor(60, 10);
  tft.println("Valj program");
  tft.fillRect(20, 28, 280, 2, MAGENTA);

  //writeMenuOptions(selectProgramMenuItems, selectProgramMenuOptions - 1);
  setSchedulingIrrigationTime();
}

void setSchedulingIrrigationTime() {
  //drawMenuSelecting(menuValue, selectProgramMenuOptions - 1);
}

void schedulingIrrigationExecutionAction() {
  switch (menuValue) {
    case 0:
      autoIrrigationMenu();
      break;
    case 1:
      //programSettings(1);
      break;
    case 2:
      //programSettings(2);
      break;
    case 3:
      //programSettings(3);
      break;
  }
}
