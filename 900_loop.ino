void loop() {
  // Initiate Blynk
  Blynk.run();

  // Read the moisture level and turn on the pump
  readMoisture();
  
  // Pause for five seconds
  delay(5000);
}
