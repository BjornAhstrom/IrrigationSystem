
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
      if (menuValue > 23) {
        menuValue = 0;
      }
      else if (menuValue < 0) {
        menuValue = 23;
      }
      showHours(menuValue, 65, 49);
      startHour = menuValue;
      break;
    case 5:
      if (menuValue > 59) {
        menuValue = 0;
      }
      else if (menuValue < 0) {
        menuValue = 59;
      }
      showMinutes(menuValue, 125, 49);
      startMinute = menuValue;
      break;
    case 6:
      if (menuValue > 24) {
        menuValue = 0;
      }
      else if (menuValue < 0) {
        menuValue = 24;
      }
      showHours(menuValue, 65, 94);
      timerHour = menuValue;
      break;
    case 7:
      if (menuValue > 59) {
        menuValue = 0;
      }
      else if (menuValue < 0) {
        menuValue = 59;
      }
      showMinutes(menuValue, 150, 94);
      timerMinute = menuValue;
      break;
    case 8:
      if (menuValue < 0) {
        menuValue = 100;
      }
      else if (menuValue > 100) {
        menuValue = 0;
      }
      showMinPercent(menuValue, 65, 139);
      break;
    case 9:
      if (menuValue < 0) {
        menuValue = 100;
      }
      else if (menuValue > 100) {
        menuValue = 0;
      }
      showMaxPercent(menuValue, 180, 139);
      break;
    case 10:
      if (menuValue < 0) {
        menuValue = 7;
      }
      else if (menuValue > 7) {
        menuValue = 0;
      }
      chooseDay(menuValue);
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
      setStartMinuteAction();
      break;
    case 5:
      setIrrigationTimeTimer();
      break;
    case 6:
      setTimerMinute();
      break;
    case 7:
      saveTimerData();
      break;
    case 8:
      saveHumidityMinPercent();
      break;
    case 9:
      saveHumidityMaxPercent();
      break;
    case 10:
      if (menuValue >= 0 && menuValue <= 6) {
        selectDay();
      } else {
        //saveIrrigationData();
        saveSelectedDays();
      }
      
      break;
    case 11:
      // Spara data
      //dateExecutionAction();
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
