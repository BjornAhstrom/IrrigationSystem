
void menuSelecting(int val) {

  switch (selectedMenu) {
    case 0:

      if (menuValue > mainMenuOptions - 1) {
        menuValue = 0;
        mainMenuValue = menuValue;
        mainMenuSelection();
      }
      else if (menuValue < 0) {
        menuValue = mainMenuOptions - 1;
        mainMenuValue = menuValue;
        mainMenuSelection();
      } else {
        mainMenuValue = menuValue;
        mainMenuSelection();
      }
      break;
    case 1:
      selectedSprinkler = val;
      //scrollMenuUpAndDown();
      break;
    case 2:
      //selectSprinklerAction = val;
      sprinklerMenuAction();
      break;
    case 3:
      if (menuValue > autoMenuOptions - 1) {
        menuValue = 0;
        selectedAutoRow = menuValue;
        autoIrrigationMenuSelection();
      }
      else if (menuValue < 0) {
        menuValue = autoMenuOptions - 1;
        selectedAutoRow = menuValue;
        autoIrrigationMenuSelection();
      } else {
        selectedAutoRow = menuValue;
        autoIrrigationMenuSelection();
      }
      break;
    case 4:
      selectedManRow = val;
      //scrollManuallIrrigationMenuUpAndDown();
      break;
    case 5:
      selectedTimeAndDateRow = val;
      adjustTimeAndDateMenu();
      break;
    case 6:
      //currentHour = val;
      hoursToAdjust();
      break;
    case 7:
      //currentMinute = val;
      minutesToAdjust();
      break;
    case 8:
      selectedDateRow = val;
      adjustDateMenu();
      break;
    case 9:
      currentYear = val;
      yearToAdjust();
      break;
    case 10:
      currentMonth = val;
      monthToAdjust();
      break;
    case 11:
      currentDay = val;
      dayToAdjust();
      break;
    case 12:
      selectedSettingsRow = val;
      //scrollSettingsMenuUpAndDown();
      break;
    case 13:
      /*if (menuValue > selectProgramMenuOptions - 1) {
        menuValue = 0;
        selectedProgramRow = menuValue;
        setSchedulingIrrigationTime();
        }
        else if (menuValue < 0) {
        menuValue = selectProgramMenuOptions - 1;
        selectedProgramRow = menuValue;
        setSchedulingIrrigationTime();
        } else {
        selectedProgramRow = menuValue;
        setSchedulingIrrigationTime();
        }*/
      break;
    case 14:
      currentIrrigationHour = val;
      showIrrigationHour();
      break;
    case 15:
      currentIrrigationMinute = val;
      showIrrigationMinute();
      break;
    case 16:
      selectedIrrigationDay = val;
      irrigationDaysMenuSelection();
      break;
    case 17:
      selectedTimeLimitSprinkler = val;
      //scrollTimeLimitSprinklerUpAndDown();
      break;
    case 18:
      if (menuValue > selectProgramMenuOptions - 1) {
        menuValue = 0;
        selectedProgramRow = menuValue;
        areaMenuSettingsSelection();
      }
      else if (menuValue < 0) {
        menuValue = selectProgramMenuOptions - 1;
        selectedProgramRow = menuValue;
        areaMenuSettingsSelection();
      } else {
        selectedProgramRow = menuValue;
        areaMenuSettingsSelection();
      }
      break;
    case 19:
      break;
    case 20:
      break;
  }
}


void menuBtnPressSelecting() {
  Serial.println("Pressed the menuBtnPressSelecting() function!!!");
  switch (selectedMenu) {
    case 0:
      mainMenuExecutionAction();
      break;
    case 1:
      sprinklerMenuExecutionAction();
      break;
    case 2:
      sprinklerExecutionAction();
      break;
    case 3:
      autoIrrigationExecuteAction();
      break;
    case 4:
      manuallIrrigationExecuteAction();
      break;
    case 5:
      adjustTimeAndDateExecutionAction();
      break;
    case 6:
      adjustMinnutes();
      break;
    case 7:
      adjustTimeExecutionAction();
      break;
    case 8:
      adjustDateExecutionAction();
      //adjustYear();
      break;
    case 9:
      adjustMonth();
      break;
    case 10:
      adjustDay();
      break;
    case 11:
      // Spara data
      dateExecutionAction();
      break;
    case 12:
      settingsExecuteAction();
      break;
    case 13:
      schedulingIrrigationExecutionAction();
      break;
    case 14:
      irrigationMinuteToSet();
      break;
    case 15:
      irrigationTimeFinnished();
      break;
    case 16:
      selectedDayExecutionAction();
      break;
    case 17:
      timeLimitSprinklerMenuExecutionAction();
      break;
    case 18:
      areaSettingsExecutionAction();
      break;
    case 19:
      break;
    case 20:
      break;
  }
}
