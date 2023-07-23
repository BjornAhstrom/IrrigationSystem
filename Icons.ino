void startTimerClockIcon(int x, int y, uint16_t iconColor, uint16_t backgroundColor) {

  // Square
  tft.fillRoundRect(x, y, 41, 41, 5, iconColor);
  tft.fillRoundRect(x + 2, y + 2, 37, 37, 5, backgroundColor);  // X, Y, width, height, Radius, color

  // Abowe circle
  tft.fillRect(x + 15, y + 5, 10, 2, iconColor);
  tft.fillRect(x + 19, y + 7, 2, 2, iconColor);

  // On the side of the circle
  tft.fillRect(x + 30, y + 11, 2, 2, iconColor);
  tft.fillRect(x + 31, y + 12, 2, 2, iconColor);
  tft.fillRect(x + 32, y + 13, 2, 2, iconColor);
  
  //tft.fillRect(40, 15, 2, 2, iconColor);

  // Circles
  tft.drawCircle(x + 20, y + 21, 12, iconColor);
  tft.drawCircle(x + 20, y + 21, 11, iconColor);
  tft.drawCircle(x + 20, y + 21, 3, iconColor);
  tft.drawCircle(x + 20, y + 21, 2, iconColor);
  tft.drawCircle(x + 20, y + 21, 1, iconColor);
  tft.drawCircle(x + 20, y + 21, 0, iconColor);

  // clock pointer
  tft.fillRect(x + 19, y + 13, 2, 10, iconColor);
  tft.fillRect(x + 19, y + 20, 3, 3, iconColor);
  
}

void hourglassIcon(int x, int y, uint16_t iconColor, uint16_t backgroundColor) {
  tft.fillRoundRect(x, y, 41, 41, 5, iconColor);
  tft.fillRoundRect(x + 2, y + 2, 37, 37, 5, backgroundColor);  // X, Y, width, height, Radius, color

  // Upper side
  tft.fillRect(x + 10, y + 7, 21, 2, iconColor);
  // Left side
  tft.fillRect(x + 10, y + 7, 2, 5, iconColor);
  // Right side
  tft.fillRect(x + 30, y + 7, 2, 5, iconColor);

  // Left side Upp
  tft.fillRect(x + 10,  y + 12, 2, 1, iconColor);
  tft.fillRect(x + 11,  y + 13, 2, 1, iconColor);
  tft.fillRect(x + 12,  y + 14, 2, 1, iconColor);
  tft.fillRect(x + 13,  y + 15, 2, 1, iconColor);  
  tft.fillRect(x + 14,  y + 16, 2, 1, iconColor);
  tft.fillRect(x + 15,  y + 17, 2, 1, iconColor);
  tft.fillRect(x + 16,  y + 18, 2, 1, iconColor);
  tft.fillRect(x + 17,  y + 19, 2, 1, iconColor);
    // Left side Down
  tft.fillRect(x + 17,  y + 20, 2, 1, iconColor);
  tft.fillRect(x + 16,  y + 21, 2, 1, iconColor);
  tft.fillRect(x + 15,  y + 22, 2, 1, iconColor);
  tft.fillRect(x + 14,  y + 23, 2, 1, iconColor);  
  tft.fillRect(x + 13,  y + 24, 2, 1, iconColor);
  tft.fillRect(x + 12,  y + 25, 2, 1, iconColor);
  tft.fillRect(x + 11,  y + 26, 2, 1, iconColor);
  tft.fillRect(x + 10,  y + 27, 2, 1, iconColor);

  // Right side Upp
  tft.fillRect(x + 29,  y + 12, 2, 1, iconColor);
  tft.fillRect(x + 28,  y + 13, 2, 1, iconColor);
  tft.fillRect(x + 27,  y + 14, 2, 1, iconColor);
  tft.fillRect(x + 26,  y + 15, 2, 1, iconColor);
  tft.fillRect(x + 25,  y + 16, 2, 1, iconColor); 
  tft.fillRect(x + 24,  y + 17, 2, 1, iconColor);
  tft.fillRect(x + 23,  y + 18, 2, 1, iconColor);
  tft.fillRect(x + 22,  y + 19, 2, 1, iconColor);
   // Right side Down
  tft.fillRect(x + 22,  y + 20, 2, 1, iconColor);
  tft.fillRect(x + 23,  y + 21, 2, 1, iconColor);
  tft.fillRect(x + 24,  y + 22, 2, 1, iconColor);
  tft.fillRect(x + 25,  y + 23, 2, 1, iconColor);  
  tft.fillRect(x + 26,  y + 24, 2, 1, iconColor);
  tft.fillRect(x + 27,  y + 25, 2, 1, iconColor);
  tft.fillRect(x + 28,  y + 26, 2, 1, iconColor);
  tft.fillRect(x + 29,  y + 27, 2, 1, iconColor);

  // Left side
  tft.fillRect(x + 10,  y + 27, 2, 5, iconColor);
  // Right side
  tft.fillRect(x + 29,  y + 27, 2, 5, iconColor);
  // Down side
  tft.fillRect(x + 10,  y + 32, 21, 2, iconColor);
  

  // Inner triangle
  // Left side Down
  //tft.fillRect(31, 72, 0, 1, iconColor);
  tft.fillRect(x + 20, y + 23, 1, 1, iconColor);
  tft.fillRect(x + 19, y + 24, 3, 1, iconColor);  
  tft.fillRect(x + 18, y + 25, 5, 1, iconColor);
  tft.fillRect(x + 17, y + 26, 7, 1, iconColor);
  tft.fillRect(x + 16, y + 27, 9, 1, iconColor);
  tft.fillRect(x + 15, y + 28, 11, 1, iconColor);
  // Right side Down
  //tft.fillRect(29, 72, 1, 1, iconColor);
  tft.fillRect(x + 20, y + 23, 1, 1, iconColor);
  tft.fillRect(x + 21, y + 24, 1, 1, iconColor);  
  tft.fillRect(x + 22, y + 25, 1, 1, iconColor);
  tft.fillRect(x + 23, y + 26, 1, 1, iconColor);
  tft.fillRect(x + 24, y + 27, 1, 1, iconColor);
  tft.fillRect(x + 25, y + 28, 1, 1, iconColor);
  
  // Down side
  tft.fillRect(x + 14, y + 29, 13, 1, iconColor);
}

void calendarIcon(int x, int y, uint16_t iconColor, uint16_t backgroundColor) {
  // Square
  tft.fillRoundRect(x, y, 41, 41, 5, iconColor);
  tft.fillRoundRect(x + 2, y + 2, 37, 37, 5, backgroundColor);  // X, Y, width, height, Radius, color


  // Outer box
  tft.fillRect(x + 15, y + 15, 21, 20, iconColor);
  tft.fillRect(x + 17, y + 17, 17, 16, backgroundColor);

  // Inner box
  tft.fillRect(x + 11, y + 15, 20, 16, iconColor);
  tft.fillRect(x + 13, y + 17, 16, 12, backgroundColor);

  // Remove top of the boxes
  tft.fillRect(x + 14, y + 15, 18, 2, backgroundColor);

  // Top
  tft.fillRect(x + 15, y + 11, 19, 2, iconColor);

  // Left side
  tft.fillRect(x + 14, y + 12, 2, 2, iconColor);
  tft.fillRect(x + 13, y + 13, 2, 2, iconColor);
  tft.fillRect(x + 12, y + 14, 2, 2, iconColor);
  tft.fillRect(x + 11, y + 15, 2, 2, iconColor);
  tft.fillRect(x + 10, y + 16, 2, 2, iconColor);
  tft.fillRect(x + 9, y + 17, 2, 2, iconColor);
  tft.fillRect(x + 8, y + 18, 2, 2, iconColor);
  tft.fillRect(x + 7, y + 19, 2, 2, iconColor);
  tft.fillRect(x + 6, y + 20, 2, 2, iconColor);
  tft.fillRect(x + 5, y + 21, 2, 2, iconColor);
  tft.fillRect(x + 4, y + 22, 2, 2, iconColor);

  // Right side
  tft.fillRect(x + 32, y + 12, 2, 2, iconColor);
  tft.fillRect(x + 31, y + 13, 2, 2, iconColor);
  tft.fillRect(x + 30, y + 14, 2, 2, iconColor);
  tft.fillRect(x + 29, y + 15, 2, 2, iconColor);
  tft.fillRect(x + 28, y + 16, 2, 2, iconColor);
  tft.fillRect(x + 27, y + 17, 2, 2, iconColor);
  tft.fillRect(x + 26, y + 18, 2, 2, iconColor);
  tft.fillRect(x + 25, y + 19, 2, 2, iconColor);
  tft.fillRect(x + 24, y + 20, 2, 2, iconColor);
  tft.fillRect(x + 23, y + 21, 2, 2, iconColor);
  tft.fillRect(x + 22, y + 22, 2, 2, iconColor);

  // Bottom
  tft.fillRect(x + 4, y + 23, 19, 2, iconColor);

  // Remove left side of the outer box
  tft.fillRect(x + 13, y + 16, 1, 1, backgroundColor);
  tft.fillRect(x + 12, y + 17, 1, 1, backgroundColor);
  tft.fillRect(x + 11, y + 18, 2, 5, backgroundColor);

  // Number 1
  tft.fillRect(x + 17, y + 15, 4, 2, iconColor);
  
  tft.fillRect(x + 21, y + 15, 3, 1, iconColor);
  tft.fillRect(x + 20, y + 16, 3, 1, iconColor);
  tft.fillRect(x + 19, y + 17, 3, 1, iconColor);
  tft.fillRect(x + 18, y + 18, 3, 1, iconColor);
  tft.fillRect(x + 17, y + 19, 3, 1, iconColor);
  tft.fillRect(x + 16, y + 20, 3, 1, iconColor);
}

void waterDropIcon(int x, int y, int radius, uint16_t color) {
  // Square
  tft.fillRoundRect(x, y, 41, 41, 5, color);
  tft.fillRoundRect(x + 2, y + 2, 37, 37, 5, GRAY);  // X, Y, width, height, Radius, color
  
  tft.fillCircle(x + 20, y + 15 + radius, radius, color); // Fyll i en cirkel som är den nedre delen av vattendroppen
  tft.fillTriangle(x + 20 - radius, y + 15 + radius, x + 20 + radius, y + 15  + radius, x + 20, y + 15 - radius, color); // Fyll i en triangel som är den övre delen av vattendroppen
}

void drawGear(int x, int y) {
  tft.fillCircle(x + 10, y + 10, 7, BLACK);
  tft.fillCircle(x + 10, y + 10, 3, GRAY);
  
  tft.fillRect(x + 9, y, 4, 4, BLACK); // Top
  tft.fillRect(x, y + 8, 4, 4, BLACK); // Left
  tft.fillRect(x + 17, y + 8, 4, 4, BLACK); // Right
  tft.fillRect(x + 9, y + 17, 4, 4, BLACK); // Bottom

  // Top right
  drawFilledRotatedRectangle(x + 16, y + 5, 45, 3, 6, BLACK); // X, Y, angle, Width, Height, Color 
  // Bottom right
  drawFilledRotatedRectangle(x + 16, y + 15, 135, 3, 6, BLACK); // X, Y, angle, Width, Height, Color
  // Top left
  drawFilledRotatedRectangle(x + 5, y + 5, 315, 3, 6, BLACK); // X, Y, angle, Width, Height, Color 
  // Bottom left
  drawFilledRotatedRectangle(x + 5, y + 15, 225, 3, 6, BLACK); // X, Y, angle, Width, Height, Color
  
}

void drawFilledRotatedRectangle(int x, int y, float angle, int width, int height, uint16_t color) {
  float angleRad = radians(angle); // 45 degrees in radians
  float halfWidth = width / 2.0;
  float halfHeight = height / 2.0;

  // Calculate the coordinates of the four corners after rotation
  int x1 = x + (int)(halfWidth * cos(angleRad) - halfHeight * sin(angleRad));
  int y1 = y + (int)(halfWidth * sin(angleRad) + halfHeight * cos(angleRad));
  int x2 = x + (int)(-halfWidth * cos(angleRad) - halfHeight * sin(angleRad));
  int y2 = y + (int)(-halfWidth * sin(angleRad) + halfHeight * cos(angleRad));
  int x3 = x + (int)(-halfWidth * cos(angleRad) + halfHeight * sin(angleRad));
  int y3 = y + (int)(-halfWidth * sin(angleRad) - halfHeight * cos(angleRad));
  int x4 = x + (int)(halfWidth * cos(angleRad) + halfHeight * sin(angleRad));
  int y4 = y + (int)(halfWidth * sin(angleRad) - halfHeight * cos(angleRad));

  // Draw filled rotated rectangle
  tft.fillTriangle(x1, y1, x2, y2, x3, y3, color);
  tft.fillTriangle(x3, y3, x4, y4, x1, y1, color);
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
