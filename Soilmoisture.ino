void setSoilmoistureValue() {
  insideStartScreen = false;
  tft.fillScreen(GRAY);
  tft.setTextColor(BLACK);
  tft.setTextSize(2);
  tft.setCursor(30, 10);
  tft.print("Stall in procent");
  tft.fillRect(20, 40, 280, 2, CYAN);
  
  setHumidityPercentMinAndMax();
}

void setHumidityPercentMinAndMax() {
  selectedMenu = 8;
  menuValue = minPercent;
  waterDropIcon(10, 130, 8, BLACK);
  startMinPercentBlinking = true;
  showMinPercent(minPercent, 65, 139);
  tft.setTextSize(2);
  tft.setCursor(125, 145);
  tft.print("%");
  tft.setCursor(139, 145);
  tft.print("min");
  showMinPercent(minPercent, 65, 139);
  tft.setTextSize(2);
  tft.setCursor(240, 145);
  tft.print("%");
  tft.setCursor(254, 145);
  tft.print("max");
  showMaxPercent(maxPercent, 180, 139);
}

void saveHumidityMinPercent() {
  startMinPercentBlinking = false;
  startMaxPercentBlinking = true;
  minPercent = menuValue;
  selectedMenu = 9;

  showMinPercent(minPercent, 65, 139);
  showMaxPercent(maxPercent, 180, 139);
  
  
}

void saveHumidityMaxPercent() {
  startMaxPercentBlinking = false;
  maxPercent = menuValue;
  showMaxPercent(maxPercent, 180, 139);
  //setDaysToIrrigate();
}
