/***************************************************
 *        Blynk and WiFi related code
 **************************************************/

// Define the VPIN's used by Blynk
#define VPIN_MOISTURE     V1 
#define VPIN_WATERLEVEL   V2
#define VPIN_CO2          V3
#define VPIN_TEMP         V4
#define VPIN_HUMIDITY     V5
#define VPIN_TERMINAL     V10

ESP8266 wifi(&EspSerial);
WidgetRTC rtc;

// Attach virtual serial terminal to vpin setting
WidgetTerminal terminal(VPIN_TERMINAL);

BLYNK_CONNECTED() {
  // Synchronize time on connection
  rtc.begin();
}

String getFormattedDate() {
  String currentTime = String(hour()) + ":" + minute();
  String currentDate = String(day()) + "-" + month() + "-" + year();
  
  return currentDate + " " + currentTime + ":";
}
