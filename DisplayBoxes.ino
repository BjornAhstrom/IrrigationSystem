void displayBoxes() {
  tft.setTextSize(2);
  drawBoxesRow(5, 285, 42, 25, 31, amountOfArea, BLACK);
  drawGear(286, 44, BLACK);
  selectBox();
}

void drawBoxesRow(int startX, int endX, int y, int boxHeight, int boxWidth, int numBoxes, uint16_t color) {
  int totalPadding = endX - startX - numBoxes * boxWidth; // Total padding between boxes
  int padding = totalPadding / (numBoxes + 1); // Padding between each box

  for (int i = 0; i < numBoxes; i++) {
    int x = startX + padding * (i + 1) + i * boxWidth; // Calculate X position for each box

    // Draw the box
    tft.setTextColor(BLACK); // Text color
    tft.fillRect(x, y, boxWidth, boxHeight, color);
    tft.fillRect(x + 2, y + 2, boxWidth - 4, boxHeight - 4, GRAY);

    // Draw the label
    tft.setTextSize(2);
    tft.setCursor(x + 5, y + 5); // Offset for label position
    tft.print("O" + String(i + 1));

    
    if (areaViews[i].areaViewName == "") {
      areaViews[i].areaViewName = String(i + 1);
    }
    
  }
}

void selectBox() {
  selectedBox(5, 285, 73, 2, 31, amountOfArea, BLACK, selectBoxIndex);
}

void selectedBox(int startX, int endX, int y, int boxHeight, int boxWidth, int numBoxes, uint16_t color, int selectedBox) {
  

  int totalPadding = endX - startX - numBoxes * boxWidth; // Total padding between boxes
  int padding = totalPadding / (numBoxes + 1); // Padding between each box
  
  
  for (int i = 0; i < numBoxes + 1; i++) {
    int x = startX + padding * (i + 1) + i * boxWidth; // Calculate X position for each box
    
    if (i == selectedBox) {
      // Draw the box
      tft.fillRect(x, y, boxWidth, boxHeight, color);
      displayStartAndIrrigationTime(selectedBox);
      if (i == amountOfArea) {
        openMainMenu = true;
        displayMenuText();
      } else {
        openMainMenu = false;
      }

    } else {
      tft.fillRect(x, y, boxWidth, boxHeight, GRAY);
    }
  }
}
