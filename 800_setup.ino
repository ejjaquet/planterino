void setup() {
  // Debug console
  Serial.begin(9600);
  delay(10);

  // Print startup message
  Serial.println("STARTING UP PLANTERINO...");

  // Set ESP8266 baud rate
  EspSerial.begin(ESP8266_BAUD);
  delay(10);

  Serial.println("Setup Wifi connection with Blynk server");
  Blynk.begin(auth, wifi, ssid, pass);

  Serial.println("Setting up sensors and actuators");
  setupWaterPump();
  setupFan();
  setupHumidifier();
  setupDHT22();
  setupSGP30();

  Serial.println("Setup is done. Initiating the loop...");
  Serial.println("=====================================");
}
