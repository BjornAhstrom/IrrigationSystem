void tftScreenSetup() {
  tft.reset();
  tft.begin(0x9341);
  tft.setRotation(1); // This settings works for me with correct orientation

  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.fillScreen(BLACK);
  tft.setCursor(120, 10);
}
