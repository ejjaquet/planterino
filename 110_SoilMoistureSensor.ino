/***************************************************
 * Capacitive Soil Moisture Sensor 
 * Pinout: VCC, GND and A6
 * 
 * Measures the amount of moisture in soil in order to activate the pump
 **************************************************/
 
float moistureValue = 0; 

void readMoisture() {
  for (int i = 0; i <= 100; i++) { 
    moistureValue = moistureValue + analogRead(MOISTUREPIN); 
    delay(1); 
  } 
  moistureValue = moistureValue/100.0;

  // Debug output
  Serial.print("Soil Moisture value: ");
  Serial.println(moistureValue);
  
  // write the value to Blynk
  Blynk.virtualWrite(VPIN_MOISTURE, moistureValue);
  
  if(moistureValue <= soilmoistureThreshold) {
    activateWaterPump();
  }
}
