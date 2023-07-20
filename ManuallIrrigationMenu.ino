void manuallIrrigationMenu() {
  selectedMenu = 4;
  selectedManRow = 0;
  menuValue = 0;
  //lcd.clear();

  manuallIrrigationMenuSelection();
}

void manuallIrrigationMenuSelection() {

  /*int startIndex = selectedManRow;
  int endIndex = startIndex + screenRows;

  if (endIndex > numOfManuallMenuRows) {
    endIndex = numOfManuallMenuRows;
    startIndex = endIndex - screenRows;
  }

  for (int i = startIndex; i < endIndex; i++) {
    lcd.setCursor(0, i);

    if (i == selectedManRow) {

      lcd.print(">");
    } else {
      lcd.print("  ");
    }
    lcd.setCursor(2, i);
    lcd.print(manIrrigationMenuItems[i]);
  }*/
}

/*void scrollManuallIrrigationMenuUpAndDown() {
  if (selectedManRow < 0) {
    selectedManRow = 0;
  } else if (selectedManRow >= numOfManuallMenuRows) {
    selectedManRow = numOfManuallMenuRows - 1;
  }

  // Update menuValue based on selected menu row
  if (selectedManRow < menuValue) {
    menuValue = selectedManRow;
  } else if (selectedManRow >= menuValue + screenRows) {
    menuValue = selectedManRow - screenRows + 1;
  }

  if (menuValue < 0) {
    menuValue = 0;
  }
  manuallIrrigationMenuSelection();
}*/

void manuallIrrigationExecuteAction() {

  switch (selectedManRow) {
    case 0:
      mainMenu();
      break;
    case 1:
      sprinklersMenu();
      break;
    case 2:
      Serial.println("Tidsbegränsning");
      timeLimitSprinkler();
      break;
  }
}
