#include <Wire.h>

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);

#include <Time.h>
#include <TimeLib.h>

#define ON   1
#define OFF  0

int screenRows = 4;
const int maxMenuRows = 10;

// Clock variables
int oldSecond = 0;
char daysOfTheWeek[7][12] = {"Sun", "Mon", "Tues", "Wed", "Thur", "Fri", "Sat"};

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
bool insideMenu = false;
int numOfMainMenuRows = 5;
int selectedMainMenuRow = 0;

char* mainMenuItems[maxMenuRows] = {
  "Tillbaka          ",
  "Auto bevattning   ",
  "Manuell bevattning",
  "Datum och tid     ",
  "Installningar     ",

  // Add more menu items if needed
};

// Auto irrigation variables
int numOfAutoMenuRows = 3;
int selectedAutoRow = 0;

char* autoIrrigationMenuItems[maxMenuRows] = {
  "Tillbaka         ",
  "Schem bevattning ",
  "Full auto        ",
};

// Manuall irrigations variabels
int numOfManuallMenuRows = 3;
int selectedManRow = 0;

char* manIrrigationMenuItems[maxMenuRows] = {
  "Tillbaka         ",
  "Valj spridare    ",
  "Tidsbegransning  ",
};


// Settings variables
int numOfSettingsMenuRows = 2;
int selectedSettingsRow = 0;

char* settingsMenuItem[maxMenuRows] = {
  "Tillbaka          ",
  "Stall in procent  ",
};

// Time and date adjustment variables
int selectedTimeAndDateRow = 0;
int selectedDateRow = 0;
bool timeIsBlinking = false;
bool setNewTime = false;
bool setNewMinute = false;
bool setNewDate = false;
bool setNewHour = false;
bool setNewYear = false;
bool setNewMonth = false;
bool setNewDay = false;
int currentHour = hour();
int currentMinute = minute();
int currentSecond = second();
int currentYear = year();
int currentMonth = month();
int currentDay = day();
unsigned long runTime = millis();

// Surface variables
bool ongoingSurface = true;
bool irrigationAuto = true;
int currentSurface = 1;

// Schematic irrigation variables
int selectedSetIrrigationTimeRow = 0;
bool activateIrrigationTime = false;
int currentIrrigationHour = 0;
bool activateIrrigationHour = false;
int currentIrrigationMinute = 0;
bool activateIrrigationMinute = false;

// Kod för att sätta vilka dagar användaren vill köra spridarna på
int scheduledTimeHour; // Tiden då spridarna ska gå igång HH
int scheduledTimeMinute; // Tiden då spridarna ska gå igång MM
unsigned long startTime; // Tiden då spridarna ska vara igång (i millisekunder)
bool allDispensersOn = false; // Flagga för att indikera om spridarna är igång

struct DaysToTurnOn {
  bool sunday;
  bool monday;
  bool tuesday;
  bool wednesday;
  bool thursday;
  bool friday;
  bool saturday;
};

DaysToTurnOn daysToTurnOn = {false, false, false, false, false, false, false}; // Välj specifika dagar att starta spridarna på

bool isScheduledTime() {
  if (hour() == scheduledTimeHour && minute() == scheduledTimeMinute) {
    return true;
  }
  return false;
}
