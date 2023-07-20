void setIrrigationDays() {
  selectedMenu = 16;
  selectedIrrigationDay = 0;
  menuValue = 0;
  /*lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("   **Valj dagar**   ");*/

  irrigationDaysMenuSelection();
}

void irrigationDaysMenuSelection() {

  /*switch (selectedIrrigationDay) {
    case -1:
      menuValue = 0;
      break;
    case 0:
      Serial.println("1");
      lcd.setCursor(0, 1);
      lcd.print("> Mandag  ");
      lcd.setCursor(15, 1);
      lcd.print(monSelected());
      lcd.setCursor(0, 2);
      lcd.print("  Tisdag  ");
      lcd.setCursor(15, 2);
      lcd.print(tuesSelected());
      lcd.setCursor(0, 3);
      lcd.print("  Onsdag  ");
      lcd.setCursor(15, 3);
      lcd.print(wedSelected());
      break;
    case 1:
      Serial.println("2");
      lcd.setCursor(0, 1);
      lcd.print("  Mandag  ");
      lcd.setCursor(15, 1);
      lcd.print(monSelected());
      lcd.setCursor(0, 2);
      lcd.print("> Tisdag  ");
      lcd.setCursor(15, 2);
      lcd.print(tuesSelected());
      lcd.setCursor(0, 3);
      lcd.print("  Onsdag  ");
      lcd.setCursor(15, 3);
      lcd.print(wedSelected());
      break;
    case 2:
      Serial.println("3");
      lcd.setCursor(0, 1);
      lcd.print("  Mandag  ");
      lcd.setCursor(15, 1);
      lcd.print(monSelected());
      lcd.setCursor(0, 2);
      lcd.print("  Tisdag  ");
      lcd.setCursor(15, 2);
      lcd.print(tuesSelected());
      lcd.setCursor(0, 3);
      lcd.print("> Onsdag  ");
      lcd.setCursor(15, 3);
      lcd.print(wedSelected());
      break;
    case 3:
      Serial.println("4");
      lcd.setCursor(0, 1);
      lcd.print("  Tisdag  ");
      lcd.setCursor(15, 1);
      lcd.print(tuesSelected());
      lcd.setCursor(0, 2);
      lcd.print("  Onsdag  ");
      lcd.setCursor(15, 2);
      lcd.print(wedSelected());
      lcd.setCursor(0, 3);
      lcd.print("> Torsdag ");
      lcd.setCursor(15, 3);
      lcd.print(thursSelected());
      break;
    case 4:
      Serial.println("5");
      lcd.setCursor(0, 1);
      lcd.print("  Onsdag  ");
      lcd.setCursor(15, 1);
      lcd.print(wedSelected());
      lcd.setCursor(0, 2);
      lcd.print("  Torsdag ");
      lcd.setCursor(15, 2);
      lcd.print(thursSelected());
      lcd.setCursor(0, 3);
      lcd.print("> Fredag  ");
      lcd.setCursor(15, 3);
      lcd.print(friSelected());
      break;
    case 5:
      Serial.println("6");
      lcd.setCursor(0, 1);
      lcd.print("  Torsdag ");
      lcd.setCursor(15, 1);
      lcd.print(thursSelected());
      lcd.setCursor(0, 2);
      lcd.print("  Fredag  ");
      lcd.setCursor(15, 2);
      lcd.print(friSelected());
      lcd.setCursor(0, 3);
      lcd.print("> Lordag  ");
      lcd.setCursor(15, 3);
      lcd.print(satSelected());
      break;
    case 6:
      Serial.println("7");
      lcd.setCursor(0, 1);
      lcd.print("  Fredag  ");
      lcd.setCursor(15, 1);
      lcd.print(friSelected());
      lcd.setCursor(0, 2);
      lcd.print("  Lordag  ");
      lcd.setCursor(15, 2);
      lcd.print(satSelected());
      lcd.setCursor(0, 3);
      lcd.print("> Sondag  ");
      lcd.setCursor(15, 3);
      lcd.print(sunSelected());
      break;
    case 7:
      lcd.setCursor(0, 1);
      lcd.print("  Lordag  ");
      lcd.setCursor(15, 1);
      lcd.print(satSelected());
      lcd.setCursor(0, 2);
      lcd.print("  Sondag  ");
      lcd.setCursor(15, 2);
      lcd.print(sunSelected());
      lcd.setCursor(0, 3);
      lcd.print("> Nasta     ");
      lcd.setCursor(12, 3);
      lcd.print("  Avbryt");
      break;
    case 8:
      lcd.setCursor(0, 1);
      lcd.print("  Lordag  ");
      lcd.setCursor(15, 1);
      lcd.print(satSelected());
      lcd.setCursor(0, 2);
      lcd.print("  Sondag  ");
      lcd.setCursor(15, 2);
      lcd.print(sunSelected());
      lcd.setCursor(0, 3);
      lcd.print("  Nasta     ");
      lcd.setCursor(12, 3);
      lcd.print("> Avbryt");
      break;
    case 9:
      menuValue = 8;
      break;
  }*/
}


void selectedDayExecutionAction() {
  switch (selectedIrrigationDay) {
    case 0:
      daysToTurnOn.monday = !daysToTurnOn.monday;
      monSelected();
      irrigationDaysMenuSelection();
      break;
    case 1:
      daysToTurnOn.tuesday = !daysToTurnOn.tuesday;
      tuesSelected();
      irrigationDaysMenuSelection();
      break;
    case 2:
      daysToTurnOn.wednesday = !daysToTurnOn.wednesday;
      wedSelected();
      irrigationDaysMenuSelection();
      break;
    case 3:
      daysToTurnOn.thursday = !daysToTurnOn.thursday;
      thursSelected();
      irrigationDaysMenuSelection();
      break;
    case 4:
      daysToTurnOn.friday = !daysToTurnOn.friday;
      friSelected();
      irrigationDaysMenuSelection();
      break;
    case 5:
      daysToTurnOn.saturday = !daysToTurnOn.saturday;
      satSelected();
      irrigationDaysMenuSelection();
      break;
    case 6:
      daysToTurnOn.sunday = !daysToTurnOn.sunday;
      sunSelected();
      irrigationDaysMenuSelection();
      break;
    case 7:
      //dispenserRunTimeScreen();
      //dispenserRunTimeIsOn = true;
      //setStartMinute = false;
      break;
    case 8:
      mainMenu();
      break;
  }
}


String monSelected() {

  if (daysToTurnOn.monday) {
    return "X";

  } else {
    return " ";
  }


}

String tuesSelected() {

  if (daysToTurnOn.tuesday) {
    return "X";
  } else {
    return " ";
  }
}

String wedSelected() {
  if (daysToTurnOn.wednesday) {
    return "X";
  } else {
    return " ";
  }
}

String thursSelected() {
  if (daysToTurnOn.thursday) {
    return "X";
  } else {
    return " ";
  }
}

String friSelected() {
  if (daysToTurnOn.friday) {
    return "X";
  } else {
    return " ";
  }
}

String satSelected() {
  if (daysToTurnOn.saturday) {
    return "X";
  } else {
    return " ";
  }
}

String sunSelected() {
  if (daysToTurnOn.sunday) {
    return "X";
  } else {
    return " ";
  }
}

/*

// runWaterDispenserOneByOne
// runAllWaterDispensers

void checkIfRightDayAndTimeToStartDispenser() {
  DateTime now = rtc.now();

  // Kontrollera om det är den utsatta tiden och en vald dag
  if (isScheduledTime(now) && !allDispensersOn && isDayToTurnOn(now.dayOfTheWeek())) {

    if (runAllWaterDispensers) {
      runAllDispensers();
    }
    else if (runWaterDispenserOneByOne) {
      autoIrrigationOn = true;
    }


    // skapa en if-sats som kollar om alla spridare ska köras, eller om dem ska köras en och en.

    startTime = millis(); // Spara starttiden
    allDispensersOn = true;
  }

}

void checkIfTimeHasPassedAndTurnOffDispensers() {
  // Kontrollera om tiden för att stänga av spridarna har passerat
  if (allDispensersOn && millis() - startTime > interval) {

    if (runAllWaterDispensers) {
      turnOffAllDispensers();
    }
    
    allDispensersOn = false;
  }

}

void turnOnLED() {
  digitalWrite(LedOut1, HIGH);
}

void turnOffLED() {
  digitalWrite(LedOut1, LOW);
}

bool isDayToTurnOn(uint8_t dayOfWeek) {
  switch (dayOfWeek) {
    case 0: // Söndag
      return daysToTurnOn.sunday;
    case 1: // Måndag
      return daysToTurnOn.monday;
    case 2: // Tisdag
      return daysToTurnOn.tuesday;
    case 3: // Onsdag
      return daysToTurnOn.wednesday;
    case 4: // Torsdag
      return daysToTurnOn.thursday;
    case 5: // Fredag
      return daysToTurnOn.friday;
    case 6: // Lördag
      return daysToTurnOn.saturday;
    default:
      return false;
  }
}*/
