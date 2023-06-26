void setup() {
  Wire.begin();
  Serial.begin(9600);

  setTime(15, 10, 38, 26, 6, 23);

  lcdScreenSetup();
  rotaryEncoderSetup();

  //mainMenu();
  startScreen();
}
