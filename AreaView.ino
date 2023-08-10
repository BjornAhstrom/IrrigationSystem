void areaView() {
  //tft.fillScreen(GRAY);
  tft.setTextSize(3);

  tft.fillRect(228, 86, 88, 30, BLACK);
  tft.fillRect(230, 88, 84, 26, GRAY);

  mockData();
  startTimerClockIcon(10, 88, BLACK, GRAY);
  hourglassIcon(10, 130, BLACK, GRAY);
  calendarIcon(10, 172, BLACK, GRAY);


}

void splitMilliseconds(long milliseconds, int &hours, int &minutes) {
  minutes = milliseconds / 60000;
  timerHour = minutes / 60;
  timerMinute = minutes % 60;
}

void displayMenuText() {
  tft.fillRect(60, 97, 200, 30, GRAY);
  tft.fillRect(60, 139, 200, 30, GRAY);
  tft.fillRect(58, 85, 320, 220, GRAY);
  tft.setTextSize(3);
  tft.setTextColor(BLACK);
  tft.setCursor(120, 100);
  tft.print("MENY");
}

void displayStartAndIrrigationTime(int selectedArea, int selectedProgram) {
  tft.setTextSize(3);
  tft.setTextColor(BLACK);

  splitMilliseconds(areaViews[selectedArea].programAreas[selectedProgram].lenghtOfIrrigation, timerHour, timerMinute);
  displayStartHours(selectedArea, selectedProgram);
  displayStartMinutes(selectedArea, 0);
  displayIrrigationTimerHours(selectedArea, selectedProgram);
  displayIrrigationTimerMinutes(selectedArea, selectedProgram);

  tft.setTextSize(2);
  tft.setCursor(60, 180);
  tft.println("Mo Tu We Th Fr Sa Su");
  selectedDay(48, 295, 200, 2, 25, 7, BLACK, selectedArea);

}

void selectedDay(int startX, int endX, int y, int boxHeight, int boxWidth, int numDays, uint16_t color, int selectedArea) {

  int totalPadding = endX - startX - numDays * boxWidth + 10; // Total padding between boxes
  int padding = totalPadding / (numDays); // Padding between each box


  for (int i = 0; i < numDays; i++) {
    int x = startX + padding * (i + 1) + i * boxWidth; // Calculate X position for each box

    if (areaViews[selectedArea].programAreas[0].daysToTurnOn.days[i]) {
      // Draw the box
      tft.fillRect(x, y, boxWidth, boxHeight, color);
    } else {
      tft.fillRect(x, y, boxWidth, boxHeight, GRAY);
    }
  }
}

void displayStartHours(int selectedArea, int selectedProgram) {
  tft.fillRect(60, 97, 150, 30, GRAY);

  int testHour = areaViews[selectedArea].programAreas[selectedProgram].startTime.hour();

  if (testHour < 10) {
    tft.setCursor(60, 97);
    tft.print("0");
    tft.setCursor(80, 97);
    tft.print(testHour);
    tft.print(":");
  } else {
    tft.setCursor(60, 97);
    tft.print(testHour);
    tft.print(":");
  }
}

int displayStartMinutes(int selectedArea, int selectedProgram) {
  int testMinute = areaViews[selectedArea].programAreas[selectedProgram].startTime.minute();

  if (testMinute < 10) {
    tft.setCursor(120, 97);
    tft.print("0");
    tft.setCursor(140, 97);
    tft.print(testMinute);
  } else {
    tft.setCursor(120, 97);
    tft.print(testMinute);
  }
}

void displayIrrigationTimerHours(int selectedArea, int selectedProgram) {
  tft.fillRect(60, 139, 200, 30, GRAY);
  tft.setTextSize(3);
  if (timerHour < 10) {
    tft.setCursor(60, 139);
    tft.print("0");
    tft.setCursor(80, 139);
    tft.print(timerHour);
    tft.setTextSize(2);
    tft.setCursor(100, 145);
    tft.print("tim");
  } else {
    tft.setCursor(60, 139);
    tft.print(timerHour);
    tft.setTextSize(2);
    tft.setCursor(100, 145);
    tft.print("tim");
  }
}

void displayIrrigationTimerMinutes(int selectedArea, int selectedProgram) {

  tft.setTextSize(3);
  if (timerMinute < 10) {
    tft.setCursor(160, 139);
    tft.print("0");
    tft.setCursor(180, 139);
    tft.print(timerMinute);
    tft.setTextSize(2);
    tft.setCursor(200, 145);
    tft.print("min");
  } else {
    tft.setCursor(160, 139);
    tft.print(timerMinute);
    tft.setTextSize(2);
    tft.setCursor(200, 145);
    tft.print("min");
  }
}

void mockData() {
  /*areaViews[0].programAreas[0].startTime = DateTime(0, 0, 0, 2, 48, 0);
    areaViews[0].programAreas[0].lenghtOfIrrigation = 35;
    areaViews[0].programAreas[0].daysToTurnOn.days[0] = true;
    areaViews[0].programAreas[0].daysToTurnOn.days[1] = true;
    areaViews[0].programAreas[0].daysToTurnOn.days[2] = true;
    areaViews[0].programAreas[0].daysToTurnOn.days[3] = true;
    areaViews[0].programAreas[0].daysToTurnOn.days[4] = true;
    areaViews[0].programAreas[0].daysToTurnOn.days[5] = true;
    areaViews[0].programAreas[0].daysToTurnOn.days[6] = true;*/

  areaViews[1].programAreas[0].startTime = DateTime(0, 0, 0, 3, 15, 0);
  areaViews[1].programAreas[0].lenghtOfIrrigation = 1080000;
  areaViews[1].programAreas[0].daysToTurnOn.days[0] = true;
  areaViews[1].programAreas[0].daysToTurnOn.days[1] = true;
  areaViews[1].programAreas[0].daysToTurnOn.days[6] = true;

  areaViews[1].programAreas[1].startTime = DateTime(0, 0, 0, 12, 0, 0);
  areaViews[1].programAreas[1].lenghtOfIrrigation = 2080000;
  areaViews[1].programAreas[1].daysToTurnOn.days[2] = true;
  areaViews[1].programAreas[1].daysToTurnOn.days[3] = true;
  areaViews[1].programAreas[1].daysToTurnOn.days[7] = true;

  areaViews[1].programAreas[2].startTime = DateTime(0, 0, 0, 21, 30, 0);
  areaViews[1].programAreas[2].lenghtOfIrrigation = 8880000;
  areaViews[1].programAreas[2].daysToTurnOn.days[1] = true;
  areaViews[1].programAreas[2].daysToTurnOn.days[4] = true;
  areaViews[1].programAreas[2].daysToTurnOn.days[5] = true;

  areaViews[2].programAreas[0].startTime = DateTime(0, 0, 0, 22, 18, 0);
  areaViews[2].programAreas[0].lenghtOfIrrigation = 960000;
  areaViews[2].programAreas[0].daysToTurnOn.days[1] = true;
  areaViews[2].programAreas[0].daysToTurnOn.days[4] = true;
  areaViews[2].programAreas[0].daysToTurnOn.days[5] = true;

  areaViews[3].programAreas[0].startTime = DateTime(0, 0, 0, 3, 15, 0);
  areaViews[3].programAreas[0].lenghtOfIrrigation = 9000000;
  areaViews[3].programAreas[0].daysToTurnOn.days[1] = true;
  areaViews[3].programAreas[0].daysToTurnOn.days[3] = true;
  areaViews[3].programAreas[0].daysToTurnOn.days[5] = true;

  areaViews[4].programAreas[0].startTime = DateTime(0, 0, 0, 12, 20, 0);
  areaViews[4].programAreas[0].lenghtOfIrrigation = 4500000;
  areaViews[4].programAreas[0].daysToTurnOn.days[4] = true;
  areaViews[4].programAreas[0].daysToTurnOn.days[5] = true;
  areaViews[4].programAreas[0].daysToTurnOn.days[6] = true;

  /*areaViews[1].programAreas[2].startTime = DateTime(0, 0, 0, 21, 30, 0);
    areaViews[1].programAreas[2].lenghtOfIrrigation = 50;
    areaViews[1].programAreas[2].daysToTurnOn.days[2] = true;
    areaViews[1].programAreas[2].daysToTurnOn.days[4] = true;
    areaViews[1].programAreas[2].daysToTurnOn.days[6] = true;*/
}
