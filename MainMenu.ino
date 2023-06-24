void mainMenu() {
  selectedMenu = 0;
  menuValue = 0;
  selectedMainMenuRow = 0;
  lcd.clear();
  /*lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("Manuell bevattning");
    lcd.setCursor(2, 1);
    lcd.print("Auto bevattning   ");
    lcd.setCursor(2, 2);
    lcd.print("Datum och tid     ");
    lcd.setCursor(2, 3);
    lcd.print("Installningar     ");*/

  mainMenuSelection();
}

void mainMenuSelection() {
  switch (selectedMainMenuRow) {
    case -1:
      selectedMainMenuRow = 0;
      menuValue = 0;
      break;
    case 0:
      lcd.setCursor(0, 0);
      lcd.print("> Tillbaka          ");
      lcd.setCursor(0, 1);
      lcd.print("  Auto bevattning   ");
      lcd.setCursor(0, 2);
      lcd.print("  Manuell bevattning");
      lcd.setCursor(0, 3);
      lcd.print("  Datum och tid     ");
      break;
    case 1:
      lcd.setCursor(0, 0);
      lcd.print("  Tillbaka          ");
      lcd.setCursor(0, 1);
      lcd.print("> Auto bevattning   ");
      lcd.setCursor(0, 2);
      lcd.print("  Manuell bevattning");
      lcd.setCursor(0, 3);
      lcd.print("  Datum och tid     ");
      break;
    case 2:
      lcd.setCursor(0, 0);
      lcd.print("  Tillbaka          ");
      lcd.setCursor(0, 1);
      lcd.print("  Auto bevattning   ");
      lcd.setCursor(0, 2);
      lcd.print("> Manuell bevattning");
      lcd.setCursor(0, 3);
      lcd.print("  Datum och tid     ");
      break;
    case 3:
      lcd.setCursor(0, 0);
      lcd.print("  Tillbaka          ");
      lcd.setCursor(0, 1);
      lcd.print("  Auto bevattning   ");
      lcd.setCursor(0, 2);
      lcd.print("  Manuell bevattning");
      lcd.setCursor(0, 3);
      lcd.print("> Datum och tid     ");
      break;
    case 4:
      lcd.setCursor(0, 0);
      lcd.print("  Auto bevattning   ");
      lcd.setCursor(0, 1);
      lcd.print("  Manuell bevattning");
      lcd.setCursor(0, 2);
      lcd.print("  Datum och tid     ");
      lcd.setCursor(0, 3);
      lcd.print("> Installningar     ");
      break;
    case 5:
      selectedMainMenuRow = 4;
      menuValue = 4;
      break;
  }
}

void mainMenuExecutionAction() {
  switch (menuValue) {
    case 0:
      selectedMenu = 1;
      startScreen();
      break;
    case 1:
      Serial.println("Auto bevattning");
      break;
    case 2:
      Serial.println("Datum och tid");
      break;
    case 3:
      Serial.println("Installningar");
      break;
    case 4:
      Serial.println("Manuell bevattning");
      break;
  }
}
