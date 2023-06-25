void sprinklersMenu() {
  selectedMenu = 1;
  selectedSprinkler = 0;
  menuValue = 0;
  lcd.clear();

  sprinklerMenu();
}

void sprinklerMenu() {
  int startIndex = selectedSprinkler;
  int endIndex = startIndex + screenRows;

  if (endIndex > numSprinklers) {
    endIndex = numSprinklers;
    startIndex = endIndex - screenRows;
  }

  for (int i = startIndex; i < endIndex; i++) {
    lcd.setCursor(0, i - startIndex);
    if (i == selectedSprinkler) {

      lcd.print(">");
    } else {
      lcd.print("  ");
    }
    lcd.setCursor(2, i - startIndex);
    lcd.print(sprinklerNames[i]);
  }
}

void scrollMenuUpAndDown() {
  if (selectedSprinkler < 0) {
    selectedSprinkler = 0;
  } else if (selectedSprinkler >= numSprinklers) {
    selectedSprinkler = numSprinklers - 1;
  }

  // Update menuValue based on selected sprinkler
  if (selectedSprinkler < menuValue) {
    menuValue = selectedSprinkler;
  } else if (selectedSprinkler >= menuValue + screenRows) {
    menuValue = selectedSprinkler - screenRows + 1;
  }

  if (menuValue < 0) {
    menuValue = 0;
  }
  sprinklerMenu();
}

void sprinklerMenuExecutionAction() {
  if (selectedSprinkler == 0) {
    manuallIrrigationMenu();
  } else {
    sprinklerName = sprinklerNames[selectedSprinkler];
    currentSelectedSprinkler = selectedSprinkler - 1;
    sprinkler();
  }
}
