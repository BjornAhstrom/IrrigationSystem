void setupTempSensor() {
  Serial.println("DHT22 sensor testing");

  //Initialize the DHT sensor
  dht.begin();
}

void displayTemperature(int x, int y) {
  temp = dht.readTemperature();
  
  tft.setCursor(x, y);
  if (oldTemp != temp) {
    dtostrf(temp, 2, 1, buffer);
    tft.fillRect(x - 1, y - 1, 60, 20, GRAY);
    tft.setTextSize(2);
    tft.setTextColor(BLACK);
    tft.setCursor(x, y);
    tft.print(buffer);
    tft.print("C");
    oldTemp = temp;
  }

}
