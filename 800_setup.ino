/***************************************************
 * Setup routine 
 **************************************************/

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
  setSyncInterval(10 * 60); // Sync interval in seconds (10 minutes)

  Serial.println("Setting up sensors and actuators");
  setupEEProm();
  setupWaterPump();
  setupFan();
  setupRelay();
  setupHumidifier();
  setupDHT22();
  setupSGP30();

  terminal.clear();
  terminal.println(F("Planterino started with Blynk v" BLYNK_VERSION));

  Serial.println("Setup is done. Initiating the loop...");
  Serial.println("=====================================");
}
