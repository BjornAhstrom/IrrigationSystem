void setup() {
  Wire.begin();
  Serial.begin(9600);

  setTime(0, 0, 0, 25, 6, 23);

  lcdScreenSetup();
  rotaryEncoderSetup();

  //mainMenu();
  startScreen();
}
