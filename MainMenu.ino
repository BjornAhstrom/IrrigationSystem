void mainMenu() {
  selectedMenu = 0;

  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("Manuell bevattning");
  lcd.setCursor(2, 1);
  lcd.print("Auto bevattning   ");
  lcd.setCursor(2, 2);
  lcd.print("Datum och tid     ");
  lcd.setCursor(2, 3);
  lcd.print("Installningar     ");

  changingMenuValue();
}

void changingMenuValue() {
  switch (mainMenuValue) {
    case -1:
      mainMenuValue = 0;
      break;
    case 0:
      lcd.setCursor(0, 0);
      lcd.print("> Manuell bevattning");
      lcd.setCursor(0, 1);
      lcd.print("  Auto bevattning   ");
      lcd.setCursor(0, 2);
      lcd.print("  Datum och tid     ");
      lcd.setCursor(0, 3);
      lcd.print("  Installningar     ");
      break;
    case 1:
      lcd.setCursor(0, 0);
      lcd.print("  Manuell bevattning");
      lcd.setCursor(0, 1);
      lcd.print("> Auto bevattning   ");
      lcd.setCursor(0, 2);
      lcd.print("  Datum och tid     ");
      lcd.setCursor(0, 3);
      lcd.print("  Installningar     ");
      break;
    case 2:
      lcd.setCursor(0, 0);
      lcd.print("  Manuell bevattning");
      lcd.setCursor(0, 1);
      lcd.print("  Auto bevattning   ");
      lcd.setCursor(0, 2);
      lcd.print("> Datum och tid     ");
      lcd.setCursor(0, 3);
      lcd.print("  Installningar     ");
      break;
    case 3:
      lcd.setCursor(0, 0);
      lcd.print("  Manuell bevattning");
      lcd.setCursor(0, 1);
      lcd.print("  Auto bevattning   ");
      lcd.setCursor(0, 2);
      lcd.print("  Datum och tid     ");
      lcd.setCursor(0, 3);
      lcd.print("> Installningar     ");
      break;
    case 4:
      lcd.setCursor(0, 0);
      lcd.print("  Auto bevattning");
      lcd.setCursor(0, 1);
      lcd.print("  Datum och tid   ");
      lcd.setCursor(0, 2);
      lcd.print("  Installningar     ");
      lcd.setCursor(0, 3);
      lcd.print("> Tillbaka     ");
      break;
      case 5:
      mainMenuValue = 4;
      break;
  }
}

void mainMenuExecutionAction() {
  switch (menuValue) {
    case 0:
      selectedMenu = 1;
      Serial.println("Manuell bevattning");
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
      mainMenu();
      break;
  }
}
