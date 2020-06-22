/**************
 * Planterino - An Arduino Mega based indoor greenhouse
 * 
 * Author: E.J. Jaquet
 * Date: 19-06-2020
 * 
 * Components used
 * - Arduino Mega
 * - DHT22 Temperature sensor
 * - SGP30 Air Quality sensor
 * - ...
 **************/

/*
Dip switch settins for Arduino Mega + Wifi:

1=ON  2=ON  3=OFF 4=OFF 5=OFF 6=OFF 7=OFF 8=OFF (ATmega2560<->ESP8266)
1=OFF 2=OFF 3=ON  4=ON  5=OFF 6=OFF 7=OFF 8=OFF (USB <->ATmega2560)
1=OFF 2=OFF 3=OFF 4=OFF 5=ON  6=ON  7=ON  8=OFF (USB<->ESP8266 (Update firmware or sketch))
1=OFF 2=OFF 3=OFF 4=OFF 5=ON  6=ON  7=OFF 8=OFF (USB<->ESP8266 (communication))
1=OFF 2=OFF 3=OFF 4=OFF 5=OFF 6=OFF 7=OFF 8=OFF (All independent)
*/


// include Blynk and other credentials
#include "credentials.h"

// Libraries used
#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>

// CO2 Sensor (SGP-30)
#include <Wire.h>
#include "Adafruit_SGP30.h"

// DHT 22 Sensor (temperature + Humidity)
#include "DHT.h"
#include <DHT_U.h>
