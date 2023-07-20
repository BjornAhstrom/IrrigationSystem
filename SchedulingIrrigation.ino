void schedulingIrrigation() {
  selectedMenu = 13;
  selectedSetIrrigationTimeRow = 0;
  menuValue = 0;
  //lcd.clear();

  //lcd.setCursor(0, 0);
  //lcd.print(" Stall in starttid ");
  setSchedulingIrrigationTime();
}

void setSchedulingIrrigationTime() {
  /*switch (selectedSetIrrigationTimeRow) {
    case -1:
      selectedSetIrrigationTimeRow = 0;
      break;
    case 0:
      // Binkande tid
      activateIrrigationTime = true;
      activatIrrigationBlinkingTime();
      lcd.setCursor(0, 3);
      lcd.print("  Nasta");
      lcd.setCursor(12, 3);
      lcd.print("  Avbryt");
      break;
    case 1:
      // Nästa
      activateIrrigationTime = false;
      showTime();
      lcd.setCursor(0, 3);
      lcd.print("> Nasta");
      lcd.setCursor(12, 3);
      lcd.print("  Avbryt");
      break;
    case 2:
      // Avbryt
      activateIrrigationTime = false;
      showTime();
      lcd.setCursor(0, 3);
      lcd.print("  Nasta");
      lcd.setCursor(12, 3);
      lcd.print("> Avbryt");
      break;
    case 3:
      selectedSetIrrigationTimeRow = 2;
      break;
  }*/
}

void schedulingIrrigationExecutionAction() {
  switch (selectedSetIrrigationTimeRow) {
    case 0:
      // Changing hour. Hour start blinking.
      irrigationHourToSet();
      break;
    case 1:
      // Nästa
      setIrrigationDays();
      break;
    case 2:
      mainMenu();
      break;
  }
}
