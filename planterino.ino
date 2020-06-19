#include "credentials.h"

#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>

// Hardware Serial on Mega, Leonardo, Micro...
#define EspSerial Serial3

// Your ESP8266 baud rate:
#define ESP8266_BAUD 115200

ESP8266 wifi(&EspSerial);

BlynkTimer timer;

void myTimerEvent()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Serial.println("Ik ga sturen");
  Blynk.virtualWrite(V1, millis() / 1000);
}

void setup() {
  // Debug console
  Serial.begin(9600);

  delay(10);

  // Set ESP8266 baud rate
  EspSerial.begin(ESP8266_BAUD);
  delay(10);

  Blynk.begin(auth, wifi, ssid, pass);

  // Setup a function to be called every second
  timer.setInterval(1000L, myTimerEvent);
}

void loop() {
  Blynk.run();
  timer.run();
}
