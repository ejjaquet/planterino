/***************************************************
 * Capacitive Soil Moisture Sensor 
 * Pinout: VCC, GND and A6
 * 
 * Measures the amount of moisture in soil in order to activate the pump
 **************************************************/

//Set dry and wet levels based on your own sensor, in my case Dry 28, wet =69
int dryPercent = 28;
int wetPercent = 69;

float soilMoistureLevel = 0;
float soilMoistureLevelf;

void readMoisture() {

  soilMoistureLevelf = analogRead(MOISTUREPIN);
  soilMoistureLevelf = (1-(soilMoistureLevelf/1023))*100;
  
  //Convert to a meaningful percentage based on our calibrated wet/dry levels defined earlier
  soilMoistureLevelf = ((soilMoistureLevelf - dryPercent)/(wetPercent-dryPercent))*100;
  soilMoistureLevel = int(soilMoistureLevelf);
  
  // Debug output
  Serial.print("Soil Moisture value: ");
  Serial.println(soilMoistureLevel);
  
  // write the value to Blynk
  Blynk.virtualWrite(VPIN_MOISTURE, soilMoistureLevel);
  
  if(soilMoistureLevel <= soilmoistureThreshold) {
    activateWaterPump();
  }
}
