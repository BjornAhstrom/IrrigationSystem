void lcdScreenSetup() {
  lcd.begin(20, 4);
  lcd.init();
  lcd.backlight();
  lcd.clear();
}
