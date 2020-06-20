void loop() {

  Serial.println("Starting the loop");

  
  // Wait a few seconds between measurements.
  delay(2000);

  // Read the moisture level and turn on the pump
  readMoisture();

  Blynk.run();
  check_status();
}
