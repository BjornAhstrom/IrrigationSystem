void rotaryEncoderSetup() {

  // Set rotary encoder pins as input
  pinMode(clk, INPUT);
  pinMode(dt, INPUT);
  pinMode(sw, INPUT_PULLUP);

  // Read the initial state of clk
  lastStateCLK = digitalRead(clk);
}


void checkRotaryEncoderStatus() {
  // Read the current state of clk
  currentStateCLK = digitalRead(clk);

  // If last and current state of clkare different, then pulse ocurred
  // React to only 1 state change to avoid double count
  if (currentStateCLK != lastStateCLK && currentStateCLK == 1) {

    // If the dt state is different than the clk state then the encoder is rotating ccw so decrement
    if (digitalRead(dt) != currentStateCLK) {
      if (insideMenu) {
        menuValue++;
      } else if (insideStartScreen) {
        selectBoxIndex++;
        if (selectBoxIndex > amountOfArea) {
          selectBoxIndex = 0;
        }
      } else if (insideAreaSettings) {
        menuValue++;
      }
      
    } else {
      if (insideMenu) {
        menuValue--;
      } else if (insideStartScreen) {
        selectBoxIndex--;
        if (selectBoxIndex < 0) {
          selectBoxIndex = amountOfArea;
        }
      } else if (insideAreaSettings) {
        menuValue--;
      }
    }

    // Add menu selecting function here
    if (insideMenu) {
      menuSelecting(menuValue);
    } else if (insideStartScreen) {
      selectBox();
    } else if (insideAreaSettings) {
        menuSelecting(menuValue);
      }
  }
  lastStateCLK = currentStateCLK;

  int btnState = digitalRead(sw);

  // If detect LOW signal from button press
  if (btnState == LOW) {

    //If 50ms have passed since last LOW pulse, it means that the
    //button has been pressed, released and pressed again
    if (millis() - lastButtonPress > 50) {

      if (openMainMenu) {
        if (insideMenu) {
          menuBtnPressSelecting();
        } else {
          insideMenu = true;
          mainMenu();
        }
      } else {
        if (insideAreaSettings) {
          menuBtnPressSelecting();
        } else {
          insideAreaSettings = true;
          areaSettings(selectBoxIndex);
        }
      }
    }

    // Remember last button press
    lastButtonPress = millis();
  }
  // Put in a slight delay to help debounce the reading
  delay(1);
}
