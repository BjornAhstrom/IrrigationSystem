
void menuSelecting(int val) {

  switch (selectedMenu) {
    case 0:
      selectedMainMenuRow = val;
      scrollMainMenuUpAndDown();
      break;
    case 1:
      selectedSprinkler = val;
      scrollMenuUpAndDown();
      break;
    case 2:
      //selectSprinklerAction = val;
      sprinklerMenuAction();
      break;
    case 3:
      selectedAutoRow = val;
      scrollAutoIrrigationMenuUpAndDown();
      break;
    case 4:
      selectedManRow = val;
      scrollManuallIrrigationMenuUpAndDown();
      break;
    case 5:
      selectedTimeAndDateRow = val;
      adjustTimeAndDateMenu();
      break;
    case 6:
      currentHour = val;
      hoursToAdjust();
      break;
    case 7:
      currentMinute = val;
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
      scrollSettingsMenuUpAndDown();
      break;
    case 13:
      selectedSetIrrigationTimeRow = val;
      setSchedulingIrrigationTime();
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
      break;
    case 17:
      break;
    case 18:
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
      break;
    case 16:
      break;
    case 17:
      break;
    case 18:
      break;
    case 19:
      break;
    case 20:
      break;
  }
}
