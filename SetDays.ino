
void setDaysToIrrigate() {
  tft.fillScreen(GRAY);
  selectedMenu = 10;
  menuValue = 0;

  calendarIcon(10, 175, BLACK, GRAY);
  tft.setTextSize(2);
  tft.setCursor(62, 184);
  tft.println("Mo Tu We Th Fr Sa Su");
  chooseDay(menuValue);

  tft.fillRoundRect(90, 219, 140, 19, 5, BLACK);
  tft.setTextSize(2);
  tft.setTextColor(GRAY);
  tft.setCursor(130, 221);
  tft.print("Spara");
}

void chooseDay(int value) {
  int totalPadding = 305 - 62 - 7 * 25 + 10; // Total padding between boxes
  int padding = totalPadding / (7); // Padding between each box

  // Draw the gray lines for all days first
  for (int i = 0; i < 7; i++) {
    int grayX = 50 + padding * (i + 1) + i * 25;
    tft.fillRect(grayX, 210, 25, 2, GRAY);

    if (areaViews[0].daysToTurnOn.days[i]) {
      tft.fillRect(grayX, 210, 25, 2, BLACK);
    }
  }

  if (value <= 6) {
    // Draw the black line for the selected day
    int x = 50 + padding * (value + 1) + value * 25; // Calculate X position for selected box
    tft.fillRect(x, 210, 25, 2, BLACK);
    tft.setTextSize(2);
    tft.setTextColor(GRAY);
    tft.setCursor(130, 221);
    tft.print("Spara");

    if (areaViews[selectBoxIndex].daysToTurnOn.days[value]) {
      tft.fillRect(x, 210, 25, 2, WHITE);
    }
  }
  else if (value == 7) {
    //tft.fillRoundRect(90, 219, 140, 19, 5, BLACK);
    tft.setTextSize(2);
    tft.setTextColor(WHITE);
    tft.setCursor(130, 221);
    tft.print("Spara");
  }
}

void selectDay() {
  areaViews[selectBoxIndex].daysToTurnOn.days[menuValue] = !areaViews[0].daysToTurnOn.days[menuValue];
  chooseDay(menuValue);
}

void saveSelectedDays() {
  areaSettings(selectBoxIndex);
}
