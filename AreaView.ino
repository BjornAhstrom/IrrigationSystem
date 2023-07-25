void areaView() {
  //tft.fillScreen(GRAY);
  tft.setTextSize(3);

  startTimerClockIcon(10, 88, BLACK, GRAY);
  tft.setCursor(60, 97);
  tft.println(areaViews[0].startTime.hour());
  
  hourglassIcon(10, 130, BLACK, GRAY);
  calendarIcon(10, 172, BLACK, GRAY);

  tft.setTextColor(BLACK);
  tft.setTextSize(2);
  tft.setCursor(55, 180);
  tft.println("Mo Tu We Th Fr Sa Su");
}
