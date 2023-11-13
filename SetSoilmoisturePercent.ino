void setSoilmoistureValue() {
  insideStartScreen = false;
  tft.fillScreen(GRAY);
  tft.setTextColor(BLACK);
  tft.setTextSize(2);
  tft.setCursor(60, 10);
  tft.print("Stall in procent");
  tft.fillRect(20, 30, 280, 2, CYAN);
  
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
  areaViews[selectBoxIndex].soilmoistureValueMin = minPercent;
  areaViews[selectBoxIndex].soilmoistureValueMax = maxPercent;
  areaSettings(selectBoxIndex);
}

void startMinPercentToBlink() {
  if (startMinPercentBlinking) {
    if (millis() - runTime >= 500) {
      runTime = millis();

      if (blinkingHumidityPercent) {
        showMinPercent(minPercent, 65, 139);
      } else {
        hideMinPercent(64, 138);
      }
      blinkingHumidityPercent = !blinkingHumidityPercent;
    }
  }
}

void startMaxPercentToBlink() {
  if (startMaxPercentBlinking) {
    if (millis() - runTime >= 500) {
      runTime = millis();

      if (blinkingHumidityPercent) {
        showMaxPercent(maxPercent, 180, 139);
      } else {
        hideMaxPercent(180, 138);
      }
      blinkingHumidityPercent = !blinkingHumidityPercent;
    }
  }
}


void showMinPercent(int percent, int y, int x) {
  minPercent = percent;
  tft.setTextSize(3);
  /*if (percent < 10) {
    tft.fillRect(y - 1, x - 1, 62, 22, GRAY);
    tft.setTextColor(BLACK);
    tft.setCursor(y, x);
    tft.println("00");
    tft.setCursor(y + 36, x);
    tft.println(percent);
    }
    else*/ if (percent < 10) {
    tft.fillRect(y - 1, x - 1, 62, 22, GRAY);
    tft.setTextColor(BLACK);
    tft.setCursor(y, x);
    tft.println("0");
    tft.setCursor(y + 20, x);
    tft.println(percent);
  }
  else {
    tft.fillRect(y - 1, x - 1, 62, 22, GRAY);
    tft.setTextColor(BLACK);
    tft.setCursor(y, x);
    tft.println(percent);
  }
}

void showMaxPercent(int percent, int y, int x) {
  maxPercent = percent;
  tft.setTextSize(3);
  /*if (percent < 10) {
    tft.fillRect(y - 1, x - 1, 62, 22, GRAY);
    tft.setTextColor(BLACK);
    tft.setCursor(y, x);
    tft.println("00");
    tft.setCursor(y + 36, x);
    tft.println(percent);
    } else*/ if (percent < 10) {
    tft.fillRect(y - 1, x - 1, 62, 22, GRAY);
    tft.setTextColor(BLACK);
    tft.setCursor(y, x);
    tft.println("0");
    tft.setCursor(y + 20, x);
    tft.println(percent);
  }
  else {
    tft.fillRect(y - 1, x - 1, 42, 22, GRAY);
    tft.setTextColor(BLACK);
    tft.setCursor(y, x);
    tft.println(percent);
  }
}





void hideMinPercent(int y, int x) {
  tft.fillRect(y, x, 52, 22, GRAY);
}

void hideMaxPercent(int y, int x) {
  tft.fillRect(y, x, 53, 22, GRAY);
}
