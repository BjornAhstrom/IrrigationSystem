void setup() {
  Wire.begin();
  Serial.begin(9600);

  delete[] areaViews;
  areaViews = new AreaView[amountOfAreaViews];
  //  setTime(15, 10, 38, 26, 6, 23);
  RTCSetup();
  //lcdScreenSetup();
  tftScreenSetup();
  rotaryEncoderSetup();
  logoScreen();
  //mainMenu();
  //startScreen();
}
