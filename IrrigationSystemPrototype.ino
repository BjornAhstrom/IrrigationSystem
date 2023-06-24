#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);

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
