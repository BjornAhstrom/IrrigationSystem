void displayProgram() {
  tft.fillRect(55, 200, 22, 2, GRAY);
  tft.fillRect(92, 200, 22, 2, GRAY);
  tft.fillRect(127, 200, 22, 2, GRAY);
  tft.fillRect(164, 200, 22, 2, GRAY);
  tft.fillRect(199, 200, 22, 2, GRAY);
  tft.fillRect(235, 200, 22, 2, GRAY);
  tft.fillRect(272, 200, 22, 2, GRAY);

  switch (selectStartScreenProgram) {
    case 0:
      sprinklerTimerIsOn = true;
      // Left box
      tft.fillRoundRect(50, 42, 51, 37, 3, BLACK);
      tft.fillRoundRect(52, 44, 47, 33, 3, GRAY);
      tft.setTextColor(WHITE);
      tft.setCursor(60, 49);
      tft.println("P1");

      // Middle box
      tft.fillRoundRect(135, 42, 51, 37, 3, LIGHTGRAY);
      tft.fillRoundRect(137, 44, 47, 33, 3, GRAY);
      tft.setTextColor(LIGHTGRAY);
      tft.setCursor(145, 49);
      tft.println("P2");

      // Right box
      tft.fillRoundRect(220, 42, 51, 37, 3, LIGHTGRAY);
      tft.fillRoundRect(222, 44, 47, 33, 3, GRAY);
      tft.setTextColor(LIGHTGRAY);
      tft.setCursor(230, 49);
      tft.println("P3");

      tft.fillRect(55, 200, 22, 2, BLACK);
      //tft.fillRect(92, 200, 22, 2, BLACK);
      tft.fillRect(127, 200, 22, 2, BLACK);
      tft.fillRect(164, 200, 22, 2, BLACK);
      tft.fillRect(199, 200, 22, 2, BLACK);
      //tft.fillRect(235, 200, 22, 2, BLACK);
      tft.fillRect(272, 200, 22, 2, BLACK);
      break;
    case 1:
      sprinklerTimerIsOn = false;
      // Left box
      tft.fillRoundRect(50, 42, 51, 37, 3, LIGHTGRAY);
      tft.fillRoundRect(52, 44, 47, 33, 3, GRAY);
      tft.setTextColor(LIGHTGRAY);
      tft.setCursor(60, 49);
      tft.println("P1");

      // Middle box
      tft.fillRoundRect(135, 42, 51, 37, 3, BLACK);
      tft.fillRoundRect(137, 44, 47, 33, 3, GRAY);
      tft.setTextColor(WHITE);
      tft.setCursor(145, 49);
      tft.println("P2");

      // Right box
      tft.fillRoundRect(220, 42, 51, 37, 3, LIGHTGRAY);
      tft.fillRoundRect(222, 44, 47, 33, 3, GRAY);
      tft.setTextColor(LIGHTGRAY);
      tft.setCursor(230, 49);
      tft.println("P3");

      tft.fillRect(55, 200, 22, 2, BLACK);
      //tft.fillRect(92, 200, 22, 2, BLACK);
      tft.fillRect(127, 200, 22, 2, BLACK);
      //tft.fillRect(164, 200, 22, 2, BLACK);
      tft.fillRect(199, 200, 22, 2, BLACK);
      //tft.fillRect(235, 200, 22, 2, BLACK);
      tft.fillRect(272, 200, 22, 2, BLACK);
      break;
    case 2:
      sprinklerTimerIsOn = true;
      // Left box
      tft.fillRoundRect(50, 42, 51, 37, 3, LIGHTGRAY);
      tft.fillRoundRect(52, 44, 47, 33, 3, GRAY);
      tft.setTextColor(LIGHTGRAY);
      tft.setCursor(60, 49);
      tft.println("P1");

      // Middle box
      tft.fillRoundRect(135, 42, 51, 37, 3, LIGHTGRAY);
      tft.fillRoundRect(137, 44, 47, 33, 3, GRAY);
      tft.setTextColor(LIGHTGRAY);
      tft.setCursor(145, 49);
      tft.println("P2");

      // Right box
      tft.fillRoundRect(220, 42, 51, 37, 3, BLACK);
      tft.fillRoundRect(222, 44, 47, 33, 3, GRAY);
      tft.setTextColor(WHITE);
      tft.setCursor(230, 49);
      tft.println("P3");

      //tft.fillRect(55, 200, 22, 2, BLACK);
      tft.fillRect(92, 200, 22, 2, BLACK);
      //tft.fillRect(127, 200, 22, 2, BLACK);
      tft.fillRect(164, 200, 22, 2, BLACK);
      //tft.fillRect(199, 200, 22, 2, BLACK);
      tft.fillRect(235, 200, 22, 2, BLACK);
      //tft.fillRect(272, 200, 22, 2, BLACK);
      break;
  }

  if (sprinklerTimerIsOn) {
    tft.fillRect(2, 216, 158, 22, BLACK);
    tft.setTextColor(GRAY);
    tft.setTextSize(2);
    tft.setCursor(70, 220);
    tft.println("ON");
    tft.fillRect(160, 216, 158, 22, GRAY);
  } else {
    tft.fillRect(160, 216, 158, 22, BLACK);
    tft.setTextColor(GRAY);
    tft.setTextSize(2);
    tft.setCursor(220, 220);
    tft.println("OFF");
    tft.fillRect(2, 216, 158, 22, GRAY);
  }
}
