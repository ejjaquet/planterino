/***************************************************
 * EEPROM code
 * 
 * setup all configuration settings from EEProm
 **************************************************/

void setupEEProm() {

  EEPROM.get(addrSoilMoistureThreshold,soilmoistureThreshold);
  EEPROM.get(addrHumidityThreshold,humidityThreshold);
  EEPROM.get(addrCo2Threshold, co2Threshold);

  Blynk.syncAll();
}
