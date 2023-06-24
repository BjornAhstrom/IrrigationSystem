#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);

#define ON   0
#define OFF  1


// Relay variables
const int relays[] = {51, 52, 53, 54, 55};
int numRelays = sizeof(relays) / sizeof(relays[0]);

// Sprinkler variables
int selectedSprinkler = 0;
int selectSprinklerAction = 0;
String sprinklerName = "";
int currentSelectedSprinkler = 0;

const int maxSprinklers = 8;
int numSprinklers =  numRelays + 1;
int screenRows = 4;

char* sprinklerNames[maxSprinklers] = {
  "Tillbaka         ",
  "Spridare 1       ",
  "Spridare 2       ",
  "Spridare 3       ",
  "Spridare 4       ",
  "Spridare 5       ",

  // Add more sprinklers if needed
};



// Rotary encoder pin variables
const int clk = 2;
const int dt = 3 ;
const int sw = 4;

// Rotary encoder  variables
int menuValue = 0;
int currentStateCLK;
int lastStateCLK;
unsigned long lastButtonPress = 0;

// Variables to menu function
int selectedMenu = 0;

// Main menu values
int selectedMainMenuRow = 0;
bool insideMenu = false;


// Surface variables
bool ongoingSurface = true;
bool irrigationAuto = true;
int currentSurface = 1;
