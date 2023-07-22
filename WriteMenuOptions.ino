void writeMenuOptions(char* menuOptions[], int numOptions) {
  tft.setTextSize(2);
  for (int i = 0; i <= numOptions; i++) {
    tft.setCursor(20, i * 25 + 40);
    tft.println(menuOptions[i]);
  }
}
