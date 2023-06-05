void rotaryEncoderSetup() {
  
  // Set rotary encoder pins as input
  pinMode(clk, INPUT);
  pinMode(dt, INPUT);
  pinMode(sw, INPUT_PULLUP);

  // Read the initial state of clk
  lastStateCLK = digitalRead(clk);
}
