float waterLevel = 0;
float waterLevelThreshold = 500;

void checkWaterLevel() {
  waterLevel = analogRead(WATERLEVELPIN);
  if(waterLevel < waterLevelThreshold) {
    Serial.println("Waterlevel: ");
    Serial.println(waterLevel);
    Blynk.notify("Planterino Alert - Waterlevel is low. Please fill the tank.");
  }
}
