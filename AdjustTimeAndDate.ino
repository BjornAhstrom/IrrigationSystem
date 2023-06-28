void adjustTimeAndDate() {
  selectedMenu = 5;
  menuValue = 0;
  selectedTimeAndDateRow = 0;
  setNewTime = true;
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Stall in tiden");

  adjustTimeAndDateMenu();
}

void adjustTimeAndDateMenu() {

  switch (selectedTimeAndDateRow) {
    case -1:
      selectedTimeAndDateRow = 0;
      break;
    case 0:
      setNewTime = true;
      showBlinkingTime();
      lcd.setCursor(0, 3);
      lcd.print("  Nasta");
      lcd.setCursor(10, 3);
      lcd.print("  Avbryt");
      break;
    case 1:
      setNewTime = false;
      setNewHour = false;
      setNewMinute = false;
      showBlinkingTime();
      lcd.setCursor(0, 3);
      lcd.print("> Nasta");
      lcd.setCursor(10, 3);
      lcd.print("  Avbryt");
      break;
    case 2:
      setNewTime = false;
      setNewHour = false;
      setNewMinute = false;
      showBlinkingTime();
      lcd.setCursor(0, 3);
      lcd.print("  Nasta");
      lcd.setCursor(10, 3);
      lcd.print("> Avbryt");
      break;
    case 3:
      selectedTimeAndDateRow = 2;
      break;
  }
}

void adjustTimeAndDateExecutionAction() {
  switch (selectedTimeAndDateRow) {
    case 0:
      adjustHour();
      break;
    case 1:
      // Ställ in datum
      adjustDate();
      break;
    case 2:
      mainMenu();
      break;
  }
}

void adjustHour() {
  selectedMenu = 6;
  menuValue = currentHour;
  setNewTime = false;
  setNewHour = true;
  hoursToAdjust();
  minutesToAdjust();
}


void adjustMinnutes() {
  selectedMenu = 7;
  menuValue = currentMinute;
  setNewTime = false;
  setNewHour = false;
  setNewMinute = true;
  hoursToAdjust();
  minutesToAdjust();
}

void adjustTimeExecutionAction() {
  selectedMenu = 5;
  selectedTimeAndDateRow = 1;
  menuValue = selectedTimeAndDateRow;
  adjustTimeAndDateMenu();
  setNewTime = false;
  setNewHour = false;
  setNewMinute = false;
  hoursToAdjust();
  minutesToAdjust();
}


void hideBlinkingHour() {

  if (currentHour < 10) {
    lcd.setCursor(0, 1);
    lcd.print(" ");
    lcd.setCursor(1, 1);
    lcd.print(" ");
  } else {
    lcd.setCursor(0, 1);
    lcd.print("  ");
  }
}

void startBlinkingHour() {
  if (setNewHour) {
    if (millis() - runTime >= 500) {
      runTime = millis();
      if (timeIsBlinking) {
        hoursToAdjust();
      } else {
        hideBlinkingHour();
      }
      timeIsBlinking = !timeIsBlinking;
    }
  }
}

void hideBlinkingMinute() {

  if (currentMinute < 10) {
    lcd.setCursor(3, 1);
    lcd.print(" ");
    lcd.setCursor(4, 1);
    lcd.print(" ");
  } else {
    lcd.setCursor(3, 1);
    lcd.print("  ");
  }
}

void startBlinkingMinute() {
  if (setNewMinute) {
    if (millis() - runTime >= 500) {
      runTime = millis();
      if (timeIsBlinking) {
        minutesToAdjust();
      } else {
        hideBlinkingMinute();
      }
      timeIsBlinking = !timeIsBlinking;
    }
  }
}

void showBlinkingTime() {

  hoursToAdjust();
  lcd.setCursor(2, 1);
  lcd.print(":");
  minutesToAdjust();
}

void hideBlinkingTime() {
  if (currentHour < 10) {
    lcd.setCursor(0, 1);
    lcd.print(" ");
    lcd.setCursor(1, 1);
    lcd.print(" ");
  } else {
    lcd.setCursor(0, 1);
    lcd.print("  ");
  }

  lcd.setCursor(2, 1);
  lcd.print(":");

  if (currentMinute < 10) {
    lcd.setCursor(3, 1);
    lcd.print(" ");
    lcd.setCursor(4, 1);
    lcd.print(" ");
  } else {
    lcd.setCursor(3, 1);
    lcd.print("  ");
  }

}

void startBlinkingTime() {
  if (setNewTime) {
    if (millis() - runTime >= 500) {
      runTime = millis();
      if (timeIsBlinking) {
        showBlinkingTime();
      } else {
        hideBlinkingTime();
      }
      timeIsBlinking = !timeIsBlinking;
    }
  }
}

// Adjust Date ----------------------------
void adjustDate() {
  selectedMenu = 8;
  menuValue = 0;
  selectedDateRow = 0;
  setNewDate = true;
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Stall in datum");

  adjustDateMenu();
}

void adjustDateMenu() {

  switch (selectedDateRow) {
    case -1:
      selectedDateRow = 0;
      break;
    case 0:
      setNewDate = true;
      showBlinkingDate();
      lcd.setCursor(0, 3);
      lcd.print("  Spara");
      lcd.setCursor(10, 3);
      lcd.print("  Avbryt");
      break;
    case 1:
      setNewDate = false;
      setNewYear = false;
      setNewMonth = false;
      setNewDay = false;
      showBlinkingDate();
      lcd.setCursor(0, 3);
      lcd.print("> Spara");
      lcd.setCursor(10, 3);
      lcd.print("  Avbryt");
      break;
    case 2:
      setNewDate = false;
      setNewYear = false;
      setNewMonth = false;
      setNewDay = false;
      showBlinkingDate();
      lcd.setCursor(0, 3);
      lcd.print("  Spara");
      lcd.setCursor(10, 3);
      lcd.print("> Avbryt");
      break;
    case 3:
      selectedDateRow = 2;
      break;
  }
}

void adjustDateExecutionAction() {
  switch (selectedDateRow) {
    case 0:
      adjustYear();
      break;
    case 1:
      // Spara all data
      saveTimeAndDate();
      break;
    case 2:
      mainMenu();
      break;
  }
}

void saveTimeAndDate() {
  setTime(currentHour, currentMinute, currentSecond, currentDay, currentMonth, currentYear);
  startScreen();
}

void dateExecutionAction() {
  selectedMenu = 8;
  selectedDateRow = 1;
  menuValue = selectedDateRow;
  adjustDateMenu();
  setNewDate = false;
  setNewYear = false;
  setNewMonth = false;
  setNewDay = false;
  yearToAdjust();
  monthToAdjust();
  dayToAdjust();
}

void adjustYear() {
  selectedMenu = 9;
  menuValue = currentYear;
  setNewDate = false;
  setNewYear = true;
  yearToAdjust();
  monthToAdjust();
  dayToAdjust();
}


void adjustMonth() {
  selectedMenu = 10;
  menuValue = currentMonth;
  setNewDate = false;
  setNewYear = false;
  setNewMonth = true;
  yearToAdjust();
  monthToAdjust();
  dayToAdjust();
}

void adjustDay() {
  selectedMenu = 11;
  menuValue = currentDay;
  setNewDate = false;
  setNewYear = false;
  setNewMonth = false;
  setNewDay = true;
  yearToAdjust();
  monthToAdjust();
  dayToAdjust();
}

void showBlinkingDate() {
  yearToAdjust();
  lcd.setCursor(4, 1);
  lcd.print("/");
  monthToAdjust();
  lcd.setCursor(7, 1);
  lcd.print("/");
  dayToAdjust();
}

void hideBlinkingDate() {
  lcd.setCursor(0, 1);
  lcd.print("    ");
  lcd.setCursor(4, 1);
  lcd.print("/");

  if (currentMonth < 10) {
    lcd.setCursor(5, 1);
    lcd.print(" ");
    lcd.setCursor(6, 1);
    lcd.print(" ");
  } else {
    lcd.setCursor(5, 1);
    lcd.print("  ");
  }

  lcd.setCursor(7, 1);
  lcd.print("/");
  if (currentDay < 10) {
    lcd.setCursor(8, 1);
    lcd.print(" ");
    lcd.setCursor(9, 1);
    lcd.print(" ");
  } else {
    lcd.setCursor(8, 1);
    lcd.print("  ");
  }
}

void startBlinkingDate() {
  if (setNewDate) {
    if (millis() - runTime >= 500) {
      runTime = millis();
      if (timeIsBlinking) {
        showBlinkingDate();
      } else {
        hideBlinkingDate();
      }
      timeIsBlinking = !timeIsBlinking;
    }
  }
}

void startBlinkingYear() {
  if (setNewYear) {
    if (millis() - runTime >= 500) {
      runTime = millis();
      if (timeIsBlinking) {
        yearToAdjust();
      } else {
        hideBlinkingYear();
      }
      timeIsBlinking = !timeIsBlinking;
    }
  }
}

void hideBlinkingYear() {
  lcd.setCursor(0, 1);
  lcd.print("    ");
}

void startBlinkingMonth() {
  if (setNewMonth) {
    if (millis() - runTime >= 500) {
      runTime = millis();
      if (timeIsBlinking) {
        monthToAdjust();
      } else {
        hideBlinkingMonth();
      }
      timeIsBlinking = !timeIsBlinking;
    }
  }
}

void hideBlinkingMonth() {
  lcd.setCursor(5, 1);
  lcd.print("  ");
}

void startBlinkingDay() {
  if (setNewDay) {
    if (millis() - runTime >= 500) {
      runTime = millis();
      if (timeIsBlinking) {
        dayToAdjust();
      } else {
        hideBlinkingDay();
      }
      timeIsBlinking = !timeIsBlinking;
    }
  }
}

void hideBlinkingDay() {
  lcd.setCursor(8, 1);
  lcd.print("  ");
}


void yearToAdjust() {
  lcd.setCursor(0, 1);
  lcd.print(currentYear);

}

void monthToAdjust() {
  if (currentMonth < 10) {
    lcd.setCursor(5, 1);
    lcd.print("0");
    lcd.setCursor(6, 1);
    lcd.print(currentMonth);
  } else {
    lcd.setCursor(5, 1);
    lcd.print(currentMonth);
  }
}

void dayToAdjust() {
  if (currentDay < 10) {
    lcd.setCursor(8, 1);
    lcd.print("0");
    lcd.setCursor(9, 1);
    lcd.print(currentDay);
  } else {
    lcd.setCursor(8, 1);
    lcd.print(currentDay);
  }
}

void hoursToAdjust() {

  if (currentHour > 23) {
    currentHour = 0;
    menuValue = 0;
  }
  else if (currentHour < 0) {
    currentHour = 23;
    menuValue = 23;
  }
  if (currentHour < 10) {
    lcd.setCursor(0, 1);
    lcd.print("0");
    lcd.setCursor(1, 1);
    lcd.print(currentHour);
  } else {
    lcd.setCursor(0, 1);
    lcd.print(currentHour);
  }
}

void minutesToAdjust() {

  if (currentMinute > 59) {
    currentMinute = 0;
    menuValue = 0;
  }
  else if (currentMinute < 0) {
    currentMinute = 59;
    menuValue = 59;
  }

  if (currentMinute < 10) {
    lcd.setCursor(3, 1);
    lcd.print("0");
    lcd.setCursor(4, 1);
    lcd.print(currentMinute);
  } else {
    lcd.setCursor(3, 1);
    lcd.print(currentMinute);
  }
}

void secondsToAdjust() {

  if (second() < 10) {
    lcd.setCursor(6, 0);
    lcd.print("0");
    lcd.setCursor(7, 0);
    lcd.print(second());
  } else {
    lcd.setCursor(6, 0);
    lcd.print(second());
  }
}
