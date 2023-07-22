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
  /*int startIndex = selectedAutoRow;
    int endIndex = startIndex + screenRows;

    if (endIndex > numOfAutoMenuRows) {
    endIndex = numOfAutoMenuRows;
    startIndex = endIndex - screenRows;
    }

    for (int i = startIndex; i < endIndex; i++) {
    lcd.setCursor(0, i);

    if (i == selectedAutoRow) {

      lcd.print(">");
    } else {
      lcd.print("  ");
    }
    lcd.setCursor(2, i);
    lcd.print(autoIrrigationMenuItems[i]);
    }*/
}

/*void scrollAutoIrrigationMenuUpAndDown() {
  if (selectedAutoRow < 0) {
    selectedAutoRow = 0;
  } else if (selectedAutoRow >= numOfAutoMenuRows) {
    selectedAutoRow = numOfAutoMenuRows - 1;
  }

  // Update menuValue based on selected menu row
  if (selectedAutoRow < menuValue) {
    menuValue = selectedAutoRow;
  } else if (selectedAutoRow >= menuValue + screenRows) {
    menuValue = selectedAutoRow - screenRows + 1;
  }

  if (menuValue < 0) {
    menuValue = 0;
  }
  autoIrrigationMenuSelection();
  }*/

void autoIrrigationExecuteAction() {

  switch (selectedAutoRow) {
    case 0:
      mainMenu();
      break;
    case 1:
      //setIrrigationHour();
      //setStartHour = true;
      Serial.println("Auto bevattning");
      schedulingIrrigation();
      break;
    case 2:

      Serial.println("Full auto");
      //fullAutoIrrigation();
      break;
  }
}
