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
      menuValue++;
      Serial.println(menuValue);
    } else {
      menuValue--;
      Serial.println(menuValue);
    }
    // Add Main menu function here
  }
  lastStateCLK = currentStateCLK;
}
