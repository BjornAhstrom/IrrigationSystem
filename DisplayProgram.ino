void displayProgram() {

  tft.setTextSize(2);
  
  tft.fillRoundRect(5, 42, 30, 25, 3, BLACK);
  tft.fillRoundRect(7, 44, 26, 21, 3, GRAY);
  tft.setCursor(9, 47);
  tft.print("O1");

  tft.fillRoundRect(40, 42, 30, 25, 3, BLACK);
  tft.fillRoundRect(42, 44, 26, 21, 3, GRAY);
  tft.setCursor(44, 47);
  tft.print("O2");

  tft.fillRoundRect(75, 42, 30, 25, 3, BLACK);
  tft.fillRoundRect(77, 44, 26, 21, 3, GRAY);
  tft.setCursor(79, 47);
  tft.print("O3");

  tft.fillRoundRect(110, 42, 30, 25, 3, BLACK);
  tft.fillRoundRect(112, 44, 26, 21, 3, GRAY);
  tft.setCursor(114, 47);
  tft.print("O4");

  tft.fillRoundRect(145, 42, 30, 25, 3, BLACK);
  tft.fillRoundRect(147, 44, 26, 21, 3, GRAY);
  tft.setCursor(149, 47);
  tft.print("O5");

  tft.fillRoundRect(180, 42, 30, 25, 3, BLACK);
  tft.fillRoundRect(182, 44, 26, 21, 3, GRAY);
  tft.setCursor(184, 47);
  tft.print("O6");

  tft.fillRoundRect(215, 42, 30, 25, 3, BLACK);
  tft.fillRoundRect(217, 44, 26, 21, 3, GRAY);
  tft.setCursor(219, 47);
  tft.print("O7");

  tft.fillRoundRect(250, 42, 30, 25, 3, BLACK);
  tft.fillRoundRect(252, 44, 26, 21, 3, GRAY);
  tft.setCursor(254, 47);
  tft.print("O8");

  drawGear(290, 44);



  /*switch (selectStartScreenProgram) {
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
    tft.fillRoundRect(2, 216, 158, 22, 3, BLACK);
    tft.setTextColor(GRAY);
    tft.setTextSize(2);
    tft.setCursor(70, 220);
    tft.println("ON");
    tft.fillRect(160, 216, 158, 22, GRAY);
    } else {
    tft.fillRoundRect(160, 216, 158, 22, 3, BLACK);
    tft.setTextColor(GRAY);
    tft.setTextSize(2);
    tft.setCursor(220, 220);
    tft.println("OFF");
    tft.fillRect(2, 216, 158, 22, GRAY);
    }*/
}
