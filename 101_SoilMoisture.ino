// Soil Moisture sensor

#define MOISTUREPIN A6
float moistureValue = 0; 

void readMoisture() {
  for (int i = 0; i <= 100; i++) { 
    moistureValue = moistureValue + analogRead(MOISTUREPIN); 
    delay(1); 
  } 
  moistureValue = moistureValue/100.0; 
  Serial.println(moistureValue);
  if(moistureValue <= 500) {
    // digitalWrite(WATERPIN, HIGH);
    delay(3000);
    // digitalWrite(WATERPIN, LOW);
  }
}
