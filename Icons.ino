void startTimerClockIcon(int x, int y) {

  // Square
  tft.fillRoundRect(x, y, 41, 41, 5, BLACK);
  tft.fillRoundRect(x + 2, y + 2, 37, 37, 5, GRAY);  // X, Y, width, height, Radius, color

  // Abowe circle
  tft.fillRect(x + 15, y + 5, 10, 2, CYAN);
  tft.fillRect(x + 19, y + 7, 2, 2, CYAN);

  // On the side of the circle
  tft.fillRect(x + 30, y + 11, 2, 2, CYAN);
  tft.fillRect(x + 31, y + 12, 2, 2, CYAN);
  tft.fillRect(x + 32, y + 13, 2, 2, CYAN);
  
  //tft.fillRect(40, 15, 2, 2, CYAN);

  // Circles
  tft.drawCircle(x + 20, y + 21, 12, CYAN);
  tft.drawCircle(x + 20, y + 21, 11, CYAN);
  tft.drawCircle(x + 20, y + 21, 3, CYAN);
  tft.drawCircle(x + 20, y + 21, 2, CYAN);
  tft.drawCircle(x + 20, y + 21, 1, CYAN);
  tft.drawCircle(x + 20, y + 21, 0, CYAN);

  // clock pointer
  tft.fillRect(x + 19, y + 13, 2, 10, CYAN);
  tft.fillRect(x + 19, y + 20, 3, 3, CYAN);
  
}

void hourglassIcon(int x, int y) {
  tft.fillRoundRect(x, y, 41, 41, 5, BLACK);
  tft.fillRoundRect(x + 2, y + 2, 37, 37, 5, GRAY);  // X, Y, width, height, Radius, color

  // Upper side
  tft.fillRect(x + 10, y + 7, 21, 2, CYAN);
  // Left side
  tft.fillRect(x + 10, y + 7, 2, 5, CYAN);
  // Right side
  tft.fillRect(x + 30, y + 7, 2, 5, CYAN);

  // Left side Upp
  tft.fillRect(x + 10,  y + 12, 2, 1, CYAN);
  tft.fillRect(x + 11,  y + 13, 2, 1, CYAN);
  tft.fillRect(x + 12,  y + 14, 2, 1, CYAN);
  tft.fillRect(x + 13,  y + 15, 2, 1, CYAN);  
  tft.fillRect(x + 14,  y + 16, 2, 1, CYAN);
  tft.fillRect(x + 15,  y + 17, 2, 1, CYAN);
  tft.fillRect(x + 16,  y + 18, 2, 1, CYAN);
  tft.fillRect(x + 17,  y + 19, 2, 1, CYAN);
    // Left side Down
  tft.fillRect(x + 17,  y + 20, 2, 1, CYAN);
  tft.fillRect(x + 16,  y + 21, 2, 1, CYAN);
  tft.fillRect(x + 15,  y + 22, 2, 1, CYAN);
  tft.fillRect(x + 14,  y + 23, 2, 1, CYAN);  
  tft.fillRect(x + 13,  y + 24, 2, 1, CYAN);
  tft.fillRect(x + 12,  y + 25, 2, 1, CYAN);
  tft.fillRect(x + 11,  y + 26, 2, 1, CYAN);
  tft.fillRect(x + 10,  y + 27, 2, 1, CYAN);

  // Right side Upp
  tft.fillRect(x + 29,  y + 12, 2, 1, CYAN);
  tft.fillRect(x + 28,  y + 13, 2, 1, CYAN);
  tft.fillRect(x + 27,  y + 14, 2, 1, CYAN);
  tft.fillRect(x + 26,  y + 15, 2, 1, CYAN);
  tft.fillRect(x + 25,  y + 16, 2, 1, CYAN); 
  tft.fillRect(x + 24,  y + 17, 2, 1, CYAN);
  tft.fillRect(x + 23,  y + 18, 2, 1, CYAN);
  tft.fillRect(x + 22,  y + 19, 2, 1, CYAN);
   // Right side Down
  tft.fillRect(x + 22,  y + 20, 2, 1, CYAN);
  tft.fillRect(x + 23,  y + 21, 2, 1, CYAN);
  tft.fillRect(x + 24,  y + 22, 2, 1, CYAN);
  tft.fillRect(x + 25,  y + 23, 2, 1, CYAN);  
  tft.fillRect(x + 26,  y + 24, 2, 1, CYAN);
  tft.fillRect(x + 27,  y + 25, 2, 1, CYAN);
  tft.fillRect(x + 28,  y + 26, 2, 1, CYAN);
  tft.fillRect(x + 29,  y + 27, 2, 1, CYAN);

  // Left side
  tft.fillRect(x + 10,  y + 27, 2, 5, CYAN);
  // Right side
  tft.fillRect(x + 29,  y + 27, 2, 5, CYAN);
  // Down side
  tft.fillRect(x + 10,  y + 32, 21, 2, CYAN);
  

  // Inner triangle
  // Left side Down
  //tft.fillRect(31, 72, 0, 1, CYAN);
  tft.fillRect(x + 20, y + 23, 1, 1, CYAN);
  tft.fillRect(x + 19, y + 24, 3, 1, CYAN);  
  tft.fillRect(x + 18, y + 25, 5, 1, CYAN);
  tft.fillRect(x + 17, y + 26, 7, 1, CYAN);
  tft.fillRect(x + 16, y + 27, 9, 1, CYAN);
  tft.fillRect(x + 15, y + 28, 11, 1, CYAN);
  // Right side Down
  //tft.fillRect(29, 72, 1, 1, CYAN);
  tft.fillRect(x + 20, y + 23, 1, 1, CYAN);
  tft.fillRect(x + 21, y + 24, 1, 1, CYAN);  
  tft.fillRect(x + 22, y + 25, 1, 1, CYAN);
  tft.fillRect(x + 23, y + 26, 1, 1, CYAN);
  tft.fillRect(x + 24, y + 27, 1, 1, CYAN);
  tft.fillRect(x + 25, y + 28, 1, 1, CYAN);
  
  // Down side
  tft.fillRect(x + 14, y + 29, 13, 1, CYAN);
}

void showStartTime() {
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.setCursor(60, 14);
  tft.println("05");
  tft.setTextSize(4);
  tft.setCursor(93, 11);
  tft.println(":");
  tft.setTextSize(3);
  tft.setCursor(110, 14);
  tft.println("15");
  tft.setTextSize(2);
  
}

void showTimerTime() {
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.setCursor(60, 60);
  tft.println("2");
  tft.setTextSize(2);
  tft.setCursor(80, 67);
  tft.println("hrs");
  tft.setTextSize(3);
  tft.setCursor(130, 60);
  tft.println("20");
  tft.setTextSize(2);
  tft.setCursor(170, 67);
  tft.println("min");
}
