
void RTCSetup() {

  if (! rtc.begin())
  {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    abort();
  }

  Serial.println("Setting the time...");
  // Ställ in rätt tid på RTC-modulen (endast första gången eller om batteriet är borttaget)
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__))); // Använd detta för att ställa in tiden enligt datorns klocka
  //rtc.adjust(DateTime(2022, 10, 31, 23, 59, 55));

  scheduledTime = DateTime(0, 0, 0, startHour, startMinute, 0); // Ange önskad tid utan att ange datum

}
