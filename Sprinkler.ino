void sprinkler() {
  selectedMenu = 2;
  menuValue = 0;
  lcd.clear();

  /*lcd.setCursor(0, 2);
    lcd.print("Fuktighet: ");
    lcd.setCursor(11, 2);
    lcd.print(42);
    lcd.setCursor(12, 2);
    lcd.print("%   ");*/

  /*if (currentSoilMoistureSensorValue < 10) {
    lcd.setCursor(0, 2);
    lcd.print("Fuktighet: ");
    lcd.setCursor(11, 2);
    lcd.print(currentSoilMoistureSensorValue);
    lcd.setCursor(12, 2);
    lcd.print("%   ");

    }
    else if (currentSoilMoistureSensorValue > 10 && currentSoilMoistureSensorValue < 100) {
    lcd.setCursor(0, 2);
    lcd.print("Fuktighet: ");
    lcd.setCursor(11, 2);
    lcd.print(currentSoilMoistureSensorValue);
    lcd.setCursor(13, 2);
    lcd.print("%   ");

    }
    else if (currentSoilMoistureSensorValue > 99) {
    lcd.setCursor(0, 2);
    lcd.print("Fuktighet: ");
    lcd.setCursor(11, 2);
    lcd.print("100");
    lcd.setCursor(14, 2);
    lcd.print("%   ");
    }*/

  sprinklerMenuAction();

}

void sprinklerMenuAction() {
  switch (menuValue) {
    case -1:
      menuValue = 0;
      break;
    case 0:
      lcd.setCursor(7, 0);
      lcd.print(sprinklerName);
      lcd.setCursor(0, 1);
      lcd.print("> Pa");
      lcd.setCursor(14, 1);
      lcd.print("  Av");
      lcd.setCursor(0, 3);
      lcd.print("  Tillbaka");
      break;
    case 1:
      lcd.setCursor(7, 0);
      lcd.print(sprinklerName);
      lcd.setCursor(0, 1);
      lcd.print("  Pa");
      lcd.setCursor(14, 1);
      lcd.print("> Av");
      lcd.setCursor(0, 3);
      lcd.print("  Tillbaka");
      break;
    case 2:
      lcd.setCursor(7, 0);
      lcd.print(sprinklerName);
      lcd.setCursor(0, 1);
      lcd.print("  Pa");
      lcd.setCursor(14, 1);
      lcd.print("  Av");
      lcd.setCursor(0, 3);
      lcd.print("> Tillbaka");
      break;
    case 3:
      menuValue = 2;
      break;
  }
}

void sprinklerExecutionAction() {
  switch (menuValue) {
    case 0:
      startSprinkler(currentSelectedSprinkler);
      break;
    case 1:
      stopSprinkler(currentSelectedSprinkler);
      break;
    case 2:
      sprinklersMenu();
      break;
  }
}

void startSprinkler(int relayPin) {
  digitalWrite(relays[relayPin], ON);
}

void stopSprinkler(int relayPin) {
  digitalWrite(relays[relayPin], OFF);
}
