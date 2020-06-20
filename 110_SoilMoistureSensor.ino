/* Soil Moisture sensor */

float moistureValue = 0; 

void readMoisture() {
  for (int i = 0; i <= 100; i++) { 
    moistureValue = moistureValue + analogRead(MOISTUREPIN); 
    delay(1); 
  } 
  moistureValue = moistureValue/100.0;
  Serial.print("Soil Moisture value: ");
  Serial.println(moistureValue);
  
  // write the value to Blynk
  Blynk.virtualWrite(V1, moistureValue);
  
  if(moistureValue <= 500) {
    // digitalWrite(WATERPIN, HIGH);
    delay(3000);
    // digitalWrite(WATERPIN, LOW);
  }
}
