void setup() {
  Wire.begin();
  Serial.begin(9600);

  lcdScreenSetup();
  rotaryEncoderSetup();
}
