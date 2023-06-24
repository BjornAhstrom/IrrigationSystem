
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
      break;
    case 4:
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
      break;
    case 4:
      break;
  }
}
