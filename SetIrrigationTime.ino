void activatIrrigationBlinkingTime() {
  if (activateIrrigationTime) {
    if (millis() - runTime >= 500) {
      runTime = millis();
      if (timeIsBlinking) {
        showTime();
      } else {
        hideTime();
      }
      timeIsBlinking = !timeIsBlinking;
    }
  }
}

void showTime() {
 showIrrigationHour();
  //lcd.setCursor(2, 1);
  //lcd.print(":");
  showIrrigationMinute();
}

void hideTime() {
  /*lcd.setCursor(0, 1);
  lcd.print("  ");
  lcd.setCursor(2, 1);
  lcd.print(":");
  lcd.setCursor(3, 1);
  lcd.print("  ");*/
}

void irrigationHourToSet() {
  selectedMenu = 14;
  activateIrrigationTime = false;
  activateIrrigationHour = true;
  menuValue = currentIrrigationHour;
}

void activateBlinkingIrrigationHour() {
  if (activateIrrigationHour) {
    if (millis() - runTime >= 500) {
      runTime = millis();
      if (timeIsBlinking) {
        showIrrigationHour();
      } else {
        hideIrrigationHour();
      }
      timeIsBlinking = !timeIsBlinking;
    }
    showIrrigationMinute();
  }
  
}

void showIrrigationHour() {
  if (currentIrrigationHour > 23) {
    currentIrrigationHour = 0;
    menuValue = currentIrrigationHour;
  }
  else if (currentIrrigationHour < 0) {
    currentIrrigationHour = 23;
    menuValue = currentIrrigationHour;
  }
  if (currentIrrigationHour < 10) {
    /*lcd.setCursor(0, 1);
    lcd.print("0");
    lcd.setCursor(1, 1);
    lcd.print(currentIrrigationHour);*/
  } else {
    //lcd.setCursor(0, 1);
    //lcd.print(currentIrrigationHour);
  }

  //lcd.setCursor(2, 1);
  //lcd.print(":");
}

void hideIrrigationHour() {
  if (currentIrrigationHour > 23) {
    currentIrrigationHour = 0;
    menuValue = currentIrrigationHour;
  }
  else if (currentIrrigationHour < 0) {
    currentIrrigationHour = 23;
    menuValue = currentIrrigationHour;
  }
  if (currentIrrigationHour < 10) {
    /*lcd.setCursor(0, 1);
    lcd.print(" ");
    lcd.setCursor(1, 1);
    lcd.print(" ");*/
  } else {
    //lcd.setCursor(0, 1);
    //lcd.print("  ");
  }

  //lcd.setCursor(2, 1);
  //lcd.print(":");
}





void irrigationMinuteToSet() {
  selectedMenu = 15;
  showIrrigationHour();
  activateIrrigationTime = false;
  activateIrrigationHour = false;
  activateIrrigationMinute = true;
  menuValue = currentIrrigationMinute;
}

void activateBlinkingIrrigationMinute() {
  if (activateIrrigationMinute) {
    if (millis() - runTime >= 500) {
      runTime = millis();
      if (timeIsBlinking) {
        showIrrigationMinute();
      } else {
        hideIrrigationMinute();
      }
      timeIsBlinking = !timeIsBlinking;
    }
  }
}


void showIrrigationMinute() {
  if (currentIrrigationMinute > 59) {
    currentIrrigationMinute = 0;
    menuValue = currentIrrigationMinute;
  }
  else if (currentIrrigationMinute < 0) {
    currentIrrigationMinute = 59;
    menuValue = currentIrrigationMinute;
  }
  if (currentIrrigationMinute < 10) {
    /*lcd.setCursor(3, 1);
    lcd.print("0");
    lcd.setCursor(4, 1);
    lcd.print(currentIrrigationMinute);*/
  } else {
    //lcd.setCursor(3, 1);
    //lcd.print(currentIrrigationMinute);
  }

  //lcd.setCursor(2, 1);
  //lcd.print(":");
}

void hideIrrigationMinute() {
  if (currentIrrigationMinute > 59) {
    currentIrrigationMinute = 0;
    menuValue = currentIrrigationMinute;
  }
  else if (currentIrrigationMinute < 0) {
    currentIrrigationMinute = 59;
    menuValue = currentIrrigationMinute;
  }
  if (currentIrrigationMinute < 10) {
    /*lcd.setCursor(3, 1);
    lcd.print(" ");
    lcd.setCursor(4, 1);
    lcd.print(" ");*/
  } else {
    //lcd.setCursor(3, 1);
    //lcd.print("  ");
  }

  //lcd.setCursor(2, 1);
  //lcd.print(":");
}

void irrigationTimeFinnished() {
  selectedMenu = 13;
  activateIrrigationMinute = false;
  selectedSetIrrigationTimeRow = 1;
  menuValue = 1;
  setSchedulingIrrigationTime();
  
}
