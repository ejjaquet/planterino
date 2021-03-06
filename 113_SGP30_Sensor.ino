/***************************************************
 * SGP30 Air quality Sensor 
 * Pinout: SCL, SDA, VCC and Ground
 * 
 * vin black
 * gnd white
 * scl grey
 * sda purple
 * 
 * Measures the air quality for co2 and triggers the fan
 **************************************************/

Adafruit_SGP30 sgp;

int sgp30Counter = 0;

void setupSGP30() {
  if (! sgp.begin()){
    Serial.println("SGP Sensor not found :(");
    while (1);
  }
  Serial.print("Found SGP30 serial #");
  Serial.print(sgp.serialnumber[0], HEX);
  Serial.print(sgp.serialnumber[1], HEX);
  Serial.println(sgp.serialnumber[2], HEX);

  // If you have a baseline measurement from before you can assign it to start, to 'self-calibrate'
  //sgp.setIAQBaseline(0x8E68, 0x8F41);  
  // Will vary for each sensor!
}

/* return absolute humidity [mg/m^3] with approximation formula
* @param temperature [°C]
* @param humidity [%RH]
*/
uint32_t getAbsoluteHumidity(float temperature, float humidity) {
    // approximation formula from Sensirion SGP30 Driver Integration chapter 3.15
    const float absoluteHumidity = 216.7f * ((humidity / 100.0f) * 6.112f * exp((17.62f * temperature) / (243.12f + temperature)) / (273.15f + temperature)); // [g/m^3]
    const uint32_t absoluteHumidityScaled = static_cast<uint32_t>(1000.0f * absoluteHumidity); // [mg/m^3]
    return absoluteHumidityScaled;
}

void readSGP30() {
  float temperature = t; // [°C]
  float humidity = h; // [%RH]
  sgp.setHumidity(getAbsoluteHumidity(temperature, humidity));

  if (! sgp.IAQmeasure()) {
    Serial.println("Measurement failed");
    terminal.print(getFormattedDate());
    terminal.println("Co2 Measurement failed!");
    return;
  }
  Serial.print("TVOC: "); 
  Serial.print(sgp.TVOC); 
  Serial.println(" ppb\t");
  Serial.print("eCO2: "); 
  Serial.print(sgp.eCO2); 
  Serial.println(" ppm");
 
  delay(1000);

  sgp30Counter++;
  if (sgp30Counter == 30) {
    sgp30Counter = 0;

    uint16_t TVOC_base, eCO2_base;
    if (! sgp.getIAQBaseline(&eCO2_base, &TVOC_base)) {
      Serial.println("Failed to get baseline readings");
      return;
    }
    Serial.print("****Baseline values: eCO2: 0x"); Serial.print(eCO2_base, HEX);
    Serial.print(" & TVOC: 0x"); Serial.println(TVOC_base, HEX);
  }

  // write the value to Blynk
  Blynk.virtualWrite(VPIN_CO2, sgp.eCO2);

  if(sgp.eCO2 > co2Threshold) {
    activateFan();
  }
}
