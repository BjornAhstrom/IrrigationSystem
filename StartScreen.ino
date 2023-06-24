void startScreen() {
  lcd.setCursor(1, 0);
  lcd.print("16:44");
  lcd.setCursor(8, 0);
  lcd.print("2023/06/24");

  lcd.setCursor(1, 1);
  lcd.print("Bevattning: ");
  lcd.setCursor(13,  1);
  lcd.print("Auto");
}
