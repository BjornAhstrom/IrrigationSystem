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
      }
    } else {
      if (insideMenu) {
        menuValue--;
      } else if (insideStartScreen) {
        selectBoxIndex--;
        if (selectBoxIndex < 0) {
          selectBoxIndex = amountOfArea;
        }
      }
    }
    // Add menu selecting function here
    if (insideMenu) {
      menuSelecting(menuValue);
    } else if (insideStartScreen) {
      selectBox();
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
          Serial.println("Main menu press 1");
        } else {
          insideMenu = true;
          mainMenu();
          Serial.println("Main menu press 2");
        }
      } else {
        Serial.println("AreaMenu() 1111111111");
      }



    }

    // Remember last button press
    lastButtonPress = millis();
  }
  // Put in a slight delay to help debounce the reading
  delay(1);
}
