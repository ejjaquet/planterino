void loop() {
  // Initiate Blynk
  Blynk.run();

  // Read the moisture level and turn on the pump
  readMoisture();

  // check the waterlevel and send an iOS alert when too low
  checkWaterLevel();

  // Pause for five seconds
  delay(5000);
}
