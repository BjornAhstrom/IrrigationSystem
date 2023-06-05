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
