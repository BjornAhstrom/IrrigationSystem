void timeLimitSprinkler() {
  selectedMenu = 17;
  selectedTimeLimitSprinkler = 0;
  menuValue = 0;
  //lcd.clear();

  timeLimitSprinklerMenu();
}
  

void timeLimitSprinklerMenu() {
  
int startIndex = selectedTimeLimitSprinkler;
  int endIndex = startIndex + screenRows;

  if (endIndex > numSprinklers) {
    endIndex = numSprinklers;
    startIndex = endIndex - screenRows;
  }

  for (int i = startIndex; i < endIndex; i++) {
    //lcd.setCursor(0, i - startIndex);
    if (i == selectedTimeLimitSprinkler) {

      //lcd.print(">");
    } else {
      //lcd.print("  ");
    }
    //lcd.setCursor(2, i - startIndex);
    //lcd.print(sprinklerNames[i]);
  }
}

void scrollTimeLimitSprinklerUpAndDown() {
  if (selectedTimeLimitSprinkler < 0) {
    selectedTimeLimitSprinkler = 0;
  } else if (selectedTimeLimitSprinkler >= numSprinklers) {
    selectedTimeLimitSprinkler = numSprinklers - 1;
  }

  // Update menuValue based on selected sprinkler
  if (selectedTimeLimitSprinkler < menuValue) {
    menuValue = selectedTimeLimitSprinkler;
  } else if (selectedTimeLimitSprinkler >= menuValue + screenRows) {
    menuValue = selectedTimeLimitSprinkler - screenRows + 1;
  }

  if (menuValue < 0) {
    menuValue = 0;
  }
  timeLimitSprinklerMenu();
}

void timeLimitSprinklerMenuExecutionAction() {
  if (selectedTimeLimitSprinkler == 0) {
    manuallIrrigationMenu();
  } else {
    sprinklerName = sprinklerNames[selectedTimeLimitSprinkler];
    currentSelectedSprinkler = selectedTimeLimitSprinkler - 1;
    //sprinkler();
  }
}
