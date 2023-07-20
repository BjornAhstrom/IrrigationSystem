void drawMenuSelecting(int menuVal, int menuOptinsAmount) {
  
  int posX = menuVal * 25 + 40;

  tft.fillRect(0, posX - 25 - 8, 2, 25, BLACK);  // Left line
  tft.fillRect(318, posX - 25 - 8, 2, 25, BLACK); // Right line
  tft.fillRect(0, posX - 25 - 8, 320, 2, BLACK); // Upper line
  tft.fillRect(0, posX - 25 + 17, 320, 2, BLACK); // Bottom line

  tft.fillRect(0, posX + 25 - 8, 2, 25, BLACK);  // Left line
  tft.fillRect(318, posX + 25 - 8, 2, 25, BLACK); // Right line
  tft.fillRect(0, posX + 25 - 8, 320, 2, BLACK); // Upper line
  tft.fillRect(0, posX + 25 + 17, 320, 2, BLACK); // Bottom line

  if (menuVal == menuOptinsAmount) {
    tft.fillRect(0, 32, 2, 25, BLACK);  // Left line
    tft.fillRect(318, 32, 2, 25, BLACK); // Right line
    tft.fillRect(0, 32, 320, 2, BLACK); // Upper line
    tft.fillRect(0, 57, 320, 2, BLACK); // Bottom line
  }
  else if (menuVal == 0) {
    tft.fillRect(0, (menuOptinsAmount * 25 + 40) - 8, 2, 25, BLACK);  // Left line
    tft.fillRect(318, (menuOptinsAmount * 25 + 40) - 8, 2, 25, BLACK); // Right line
    tft.fillRect(0, (menuOptinsAmount * 25 + 40) - 8, 320, 2, BLACK); // Upper line
    tft.fillRect(0, (menuOptinsAmount * 25 + 40) + 17, 320, 2, BLACK); // Bottom line
  }

  tft.fillRect(0, posX - 8, 2, 25, CYAN);  // Left line
  tft.fillRect(318, posX - 8, 2, 25, CYAN); // Right line
  tft.fillRect(0, posX - 8, 320, 2, CYAN); // Upper line
  tft.fillRect(0, posX + 17, 320, 2, CYAN); // Bottom line
}
