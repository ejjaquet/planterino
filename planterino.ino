/**************
 * Planterino - An Arduino Mega based indoor greenhouse
 * 
 * Author: E.J. Jaquet
 * Date: 19-06-2020
 * 
 * Components used:
 * - Arduino Mega + WiFi
 * - DHT22 Temperature sensor
 * - SGP30 Air Quality sensor
 * - Capacitive Soil Moisture sensor
 * - Realtime Clock
 * - Waterlevel sensor
 * - 5v waterpump
 * - 5v fan
 * - Grove Water Atomizer (Reichelt)
 * - 12v Relay
 **************/

/***************************************************
*   Dip switch settins for Arduino Mega + Wifi:
*   1=ON  2=ON  3=OFF 4=OFF 5=OFF 6=OFF 7=OFF 8=OFF (ATmega2560<->ESP8266)
*   1=OFF 2=OFF 3=ON  4=ON  5=OFF 6=OFF 7=OFF 8=OFF (USB <->ATmega2560)
*   1=OFF 2=OFF 3=OFF 4=OFF 5=ON  6=ON  7=ON  8=OFF (USB<->ESP8266 (Update firmware or sketch))
*   1=OFF 2=OFF 3=OFF 4=OFF 5=ON  6=ON  7=OFF 8=OFF (USB<->ESP8266 (communication))
*   1=OFF 2=OFF 3=OFF 4=OFF 5=OFF 6=OFF 7=OFF 8=OFF (All independent)
 **************************************************/

// include Blynk and other credentials
#include "credentials.h"

/***************************************************
 *        Libraries used
 **************************************************/

// Blynk + WiFi
#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>

// CO2 Sensor (SGP-30)
#include <Wire.h>
#include "Adafruit_SGP30.h"

// DHT 22 Sensor (temperature + Humidity)
#include "DHT.h"
#include <DHT_U.h>

// Realtime Clock
#include <RTClib.h>

// Chrono library for multitasking
#include  <Chrono.h>

// EEPROM for saving configuration
#include <EEPROM.h>

/***************************************************
 *        Blynk code for updating settings.
 *        For some reason this needs to be
 *        in the main file, otherwise compilation
 *        will fail.
 **************************************************/

// Settings used
int addrHumidityThreshold = 0;
float humidityThreshold;

int addrCo2Threshold = 10;
float co2Threshold;

int addrSoilMoistureThreshold = 20;
float soilmoistureThreshold;

BLYNK_WRITE(V20) {
  int pinValue = param.asInt();
  humidityThreshold = (float)pinValue;
  
  EEPROM.put(addrHumidityThreshold, humidityThreshold);
  Serial.println("Saving...");
  humidityThreshold = 0;
  EEPROM.get(addrHumidityThreshold, humidityThreshold);
  Serial.println(humidityThreshold);
}

BLYNK_WRITE(V21) {
  int pinValue = param.asInt();
  co2Threshold = (float)pinValue;
  
  EEPROM.put(addrCo2Threshold, co2Threshold);
  Serial.println("Saving...");
  co2Threshold = 0;
  EEPROM.get(addrCo2Threshold, co2Threshold);
  Serial.println(co2Threshold);
}

BLYNK_WRITE(V22) {
  int pinValue = param.asInt();
  soilmoistureThreshold = (float)pinValue;
  
  EEPROM.put(addrSoilMoistureThreshold, soilmoistureThreshold);
  Serial.println("Saving...");
  soilmoistureThreshold = 0;
  EEPROM.get(addrSoilMoistureThreshold, soilmoistureThreshold);
  Serial.println(soilmoistureThreshold);
}

BLYNK_WRITE(V23) {
  int pinValue = param.asInt();
  digitalWrite(25, pinValue);
}
