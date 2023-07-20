void mainMenu() {
  selectedMenu = 0;
  selectedMainMenuRow = 0;
  menuValue = 0;
  //lcd.clear();
  
  tft.println("Meny");
  tft.fillRect(20, 28, 280, 2, MAGENTA);

  mainMenuSelection();
}

void mainMenuSelection() {
  writeMenuOptions(mainMenuItems, numOfMainMenuRows);
  /*int startIndex = selectedMainMenuRow;
  int endIndex = startIndex + screenRows;

  if (endIndex > numOfMainMenuRows) {
    endIndex = numOfMainMenuRows;
    startIndex = endIndex - screenRows;
  }

  for (int i = startIndex; i < endIndex; i++) {
    lcd.setCursor(0, i - startIndex);
    if (i == selectedMainMenuRow) {

      lcd.print(">");
    } else {
      lcd.print("  ");
    }
    lcd.setCursor(2, i - startIndex);
    lcd.print(mainMenuItems[i]);
  }*/
}

/*void scrollMainMenuUpAndDown() {
  if (selectedMainMenuRow < 0) {
    selectedMainMenuRow = 0;
  } else if (selectedMainMenuRow >= numOfMainMenuRows) {
    selectedMainMenuRow = numOfMainMenuRows - 1;
  }

  // Update menuValue based on selected menu row
  if (selectedMainMenuRow < menuValue) {
    menuValue = selectedMainMenuRow;
  } else if (selectedMainMenuRow >= menuValue + screenRows) {
    menuValue = selectedMainMenuRow - screenRows + 1;
  }

  if (menuValue < 0) {
    menuValue = 0;
  }
  mainMenuSelection();
}*/

void mainMenuExecutionAction() {
  switch (selectedMainMenuRow) {
    case 0:
      selectedMenu = 1;
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
