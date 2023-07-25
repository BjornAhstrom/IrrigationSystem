#include <Wire.h>
#include "RTClib.h"

// TFT screen variables
// Modified for SPFD5408 Library by Joao Lopes
#include <SPFD5408_Adafruit_GFX.h>  // Core graphics library  
#include <SPFD5408_Adafruit_TFTLCD.h> // Hardware-specific library  
#include <SPFD5408_TouchScreen.h>

// Pin assignments for the TFT touch screen
#define YP  A1
#define XM  A2
#define YM  7
#define XP  6

// Calibrated values for the TFT touch screen
#define TS_MINX  178
#define TS_MINY  75
#define TS_MAXX  931
#define TS_MAXY  895


// Instantiate the ts object
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);
#define LCD_RD  A0
#define LCD_WR  A1
#define LCD_CD  A2
#define LCD_CS  A3
#define LCD_RESET A4


// Instantiate the tft object
Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

// Assign human-readable names to some common 16-bit color values:
#define BLACK  0x0000
#define BLUE  0x001F
#define RED   0xF800
#define GREEN  0x07E0
#define CYAN  0x07FF
#define MAGENTA 0xF81F
#define YELLOW 0xFFE0
#define WHITE  0xFFFF
#define GRAY  0xc658
#define LIGHTGRAY 0xf7be

#define MINPRESSURE 10
#define MAXPRESSURE 1000

RTC_DS3231 rtc;

// Rotary encoder pin variables
const int clk = 53;
const int dt = 52 ;
const int sw = 51;

// Rotary encoder  variables
int menuValue = 0;
int currentStateCLK;
int lastStateCLK;
unsigned long lastButtonPress = 0;
bool openMainMenu = false;

#define ON   1
#define OFF  0

int screenRows = 4;
const int maxMenuRows = 10;

// Clock variables
int oldSecond = 0;
int oldMinute = 0;
int oldHour = 0;

// Date variables
int year;
int month;
int day;
int oldDay;
int oldMonth;
int oldYear;

// Clock variabels
int hours;
int minutes;
int seconds;

char daysOfTheWeek[7][12] = {"Sun", "Mon", "Tues", "Wed", "Thur", "Fri", "Sat"};

// Relay variables
const int relays[] = {51, 52, 53, 54, 55};
int numRelays = sizeof(relays) / sizeof(relays[0]);

// Sprinkler variables
int selectedSprinkler = 0;
int selectSprinklerAction = 0;
String sprinklerName = "";
int currentSelectedSprinkler = 0;
bool sprinklerTimerIsOn = false;

// Time limit sprinkler variables
int selectedTimeLimitSprinkler = 0;

//const int maxSprinklers = 8;
int numSprinklers =  numRelays + 1;

char* sprinklerNames[] = {
  "Tillbaka         ",
  "Spridare 1       ",
  "Spridare 2       ",
  "Spridare 3       ",
  "Spridare 4       ",
  "Spridare 5       ",

  // Add more sprinklers if needed
};

// Variables to menu function
int selectedMenu = 0;

// Main menu values

//int numOfMainMenuRows = 4;
//int selectedMainMenuRow = 0;

char* mainMenuItems[] = {
  "Tillbaka          ",
  "Automatisk bevattning   ",
  "Manuell bevattning",
  "Datum och tid     ",
  "Installningar     ",

  // Add more menu items if needed
};

bool insideMenu = false;
int mainMenuValue = 0;
int mainMenuOptions = sizeof(mainMenuItems) / sizeof(mainMenuItems[0]);

// Auto irrigation variables
char* autoIrrigationMenuItems[] = {
  "Tillbaka         ",
  "Schemalagd bevattning ",
  "Full auto        ",
};

int autoMenuOptions = sizeof(autoIrrigationMenuItems) / sizeof(autoIrrigationMenuItems[0]);
int selectedAutoRow = 0;
/*
// Auto select program variables
char* selectProgramMenuItems[] = {
  "Tillbaka         ",
  "Program 1 ",
  "Program 2 ",
  "Program 3 ",
};

int selectProgramMenuOptions = sizeof(selectProgramMenuItems) / sizeof(selectProgramMenuItems[0]);
int selectedProgramRow = 0;
*/


// Manuall irrigations variabels
int numOfManuallMenuRows = 3;
int selectedManRow = 0;

char* manIrrigationMenuItems[] = {
  "Tillbaka         ",
  "Valj spridare    ",
  "Tidsbegransning  ",
};


// Settings variables
int numOfSettingsMenuRows = 2;
int selectedSettingsRow = 0;

char* settingsMenuItem[] = {
  "Tillbaka          ",
  "Stall in procent  ",
};

// Irrigation days variables
int numOfIrrigationDaysRows = 10;
int selectedIrrigationDay = 0;

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
int currentHour = 0;
int currentMinute = 0;
int currentSecond = 0;
int currentYear = 0;
int currentMonth = 0;
int currentDay = 0;
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
DateTime scheduledTime; // Tiden då spridarna ska gå igång HH:MM:SS
unsigned long startTime; // Tiden då spridarna ska vara igång (i millisekunder)
bool allDispensersOn = false; // Flagga för att indikera om spridarna är igång


// Variables to set irrigation start time
int startHour = 0;
int startMinute = 0;
unsigned long dispenserRunTime = 0;  // Time is in minutes
int dispenserRuntimeHour = 0;
int dispenserRunTimeRemainderMinutes = 0;
unsigned long startTimeDispenser = 0;

// Start screen variables
int selectStartScreenProgram = 0;
bool insideStartScreen = false;
bool runTimeAndDateOnes = false;

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

bool isScheduledTime(const DateTime& currentTime) {
  if (currentTime.hour() == scheduledTime.hour() && currentTime.minute() == scheduledTime.minute()) {
    return true;
  }
  return false;
}

class AreaView {
  public:
    String areaViewName;
    int soilmoistureValue;
    DateTime startTime;
    DateTime irrigationLenght;
    DaysToTurnOn daysToTurnOn;

    AreaView() {
      areaViewName = "";
      soilmoistureValue = 0;
      startTime = DateTime();
      irrigationLenght = DateTime();
      daysToTurnOn = DaysToTurnOn();
    }

};
// Choose area variables
int amountOfArea = 8;
const int amountOfAreaViews = amountOfArea;
int selectBoxIndex = 0;

AreaView* areaViews;
