/***************************************************
 * The actual execution of the code, 
 * pauses for 5 seconds and continues
 **************************************************/
 
void loop() {
  // Initiate Blynk
  Blynk.run();

  // Read the moisture level and turn on the pump
  readMoisture();

  // check the waterlevel and send an iOS alert when too low
  checkWaterLevel();

  // Read temperature and humidity and turn on humidifier
  readTemp();

  // Calculate CO2 and turn on fans
  readSGP30();

  // Check the time and turn lights on or off
  checkTime();

  Serial.println("=====================================");

  // Pause for five seconds
  delay(5000);
}
