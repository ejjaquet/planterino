/***************************************************
 * EEPROM code
 * 
 * setup all configuration settings from EEProm
 **************************************************/

void setupEEProm() {

  EEPROM.get(addrSoilMoistureThreshold,soilmoistureThreshold);  //Get the upper moisture threshold

  Blynk.syncAll();
}
