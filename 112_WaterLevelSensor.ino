/***************************************************
 * Water level Sensor 
 * Pinout: VCC, GND and A7
 * 
 * Measures the water level and sends an iOS alert when
 * tank is almost empty
 **************************************************/

float waterLevel = 0;
float waterLevelThreshold = -10;

void checkWaterLevel() {
  waterLevel = analogRead(WATERLEVELPIN);

  Serial.print("Waterlevel: ");
  Serial.println(waterLevel);

  // write the value to Blynk
  Blynk.virtualWrite(VPIN_WATERLEVEL, waterLevel);

  if(waterLevel < waterLevelThreshold) {
    terminal.print(getFormattedDate());
    terminal.println("The water level is low!!");
    Blynk.notify("Planterino Alert - Waterlevel is low. Please fill the tank.");
  }
}
