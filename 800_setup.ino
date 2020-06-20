void setup() {
  // Debug console
  Serial.begin(9600);
  delay(1000);

  // initialize serial for ESP module
  EspSerial.begin(ESP8266_BAUD);
  Serial.println("Start Blynk_WM using ESP_AT_Shield on " + String(BOARD_TYPE));
  delay(1000);

  Blynk.setConfigPortal("Planterino", "MyPlanterino");
  Blynk.begin(wifi);
}
