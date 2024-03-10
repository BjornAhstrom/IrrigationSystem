void setup() {
  Wire.begin();
  Serial.begin(9600);

  delete[] areaViews;
  areaViews = new AreaView[amountOfAreaViews];
  //  setTime(15, 10, 38, 26, 6, 23);
  setupTempSensor();
  RTCSetup();
  //mockData();
  //lcdScreenSetup();
  tftScreenSetup();
  rotaryEncoderSetup();
  startScreen();
  //logoScreen();
  //mainMenu();
  //startScreen();

  for (int i = 0; i < numRelays; i++) {
    pinMode(relays[i], OUTPUT);
  }

  
}
