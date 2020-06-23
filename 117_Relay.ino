/***************************************************
 * 12 volt relay
 * Pinout: VCC, GND and D25
 * 
 * Relay used to control the lights
 **************************************************/

void setupRelay() {
  pinMode(RELAYPIN, OUTPUT);
  digitalWrite(RELAYPIN, LOW);
}
