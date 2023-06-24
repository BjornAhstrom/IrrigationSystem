void startScreen() {
  insideMenu = false;
  
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("16:44");
  lcd.setCursor(8, 0);
  lcd.print("2023/06/24");

  lcd.setCursor(0, 1);
  lcd.print("Bevattning: ");

  if (irrigationAuto) {
    lcd.setCursor(12,  1);
    lcd.print("Auto");
  } else {
    lcd.setCursor(12,  1);
    lcd.print("Man");
  }



  if (ongoingSurface) {
    lcd.setCursor(0, 2);
    lcd.print("Pagaende yta:");
    lcd.setCursor(14, 2);
    lcd.print(currentSurface);
  } else {
    lcd.setCursor(0, 2);
    lcd.print("Bevattning avstangd");
  }
}
