void settings() {
 // lcd.clear();
  selectedMenu = 12;
  selectedSettingsRow = 0;
  menuValue = 0;

  settingsMenu();
}

void settingsMenu() {
    writeMenuOptions(settingsMenuItem, numOfSettingsMenuRows);
  /*int startIndex = selectedSettingsRow;
  int endIndex = startIndex + screenRows;

  if (endIndex > numOfSettingsMenuRows) {
    endIndex = numOfSettingsMenuRows;
    startIndex = endIndex - screenRows;
  }

  for (int i = startIndex; i < endIndex; i++) {
    lcd.setCursor(0, i);

    if (i == selectedSettingsRow) {

      lcd.print(">");
    } else {
      lcd.print("  ");
    }
    lcd.setCursor(2, i);
    lcd.print(settingsMenuItem[i]);
  }*/
}

/*void scrollSettingsMenuUpAndDown() {
  if (selectedSettingsRow < 0) {
    selectedSettingsRow = 0;
  } else if (selectedSettingsRow >= numOfSettingsMenuRows) {
    selectedSettingsRow = numOfSettingsMenuRows - 1;
  }

  // Update menuValue based on selected menu row
  if (selectedSettingsRow < menuValue) {
    menuValue = selectedSettingsRow;
  } else if (selectedSettingsRow >= menuValue + screenRows) {
    menuValue = selectedSettingsRow - screenRows + 1;
  }

  if (menuValue < 0) {
    menuValue = 0;
  }
  settingsMenu();
}*/

void settingsExecuteAction() {

  switch (selectedSettingsRow) {
    case 0:
      mainMenu();
      break;
    case 1:
      Serial.println("Ställ in procent");
      break;
  }
}
