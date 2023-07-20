void startScreen() {
  tft.fillScreen(GRAY);
  tft.setTextSize(3);
  insideMenu = false;

   tft.fillRect(0, 32, 320, 2, BLACK);

   // Left box
   tft.fillRoundRect(50, 47, 51, 37, 3, BLACK);
   tft.fillRoundRect(52, 49, 47, 33, 3, GRAY);
   tft.setCursor(60, 54);
   tft.println("P1");
   
   // Middle box
   tft.fillRoundRect(135, 47, 51, 37, 3, LIGHTGRAY);
   tft.fillRoundRect(137, 49, 47, 33, 3, GRAY);
   tft.setTextColor(LIGHTGRAY);
   tft.setCursor(145, 54);
   tft.println("P2");

   // Right box
   tft.fillRoundRect(220, 47, 51, 37, 3, LIGHTGRAY);
   tft.fillRoundRect(222, 49, 47, 33, 3, GRAY);
   tft.setTextColor(LIGHTGRAY);
   tft.setCursor(230, 54);
   tft.println("P3");

   tft.fillRect(0, 90, 320, 2, BLACK);
}
