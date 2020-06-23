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

void startRelay() {
  terminal.print(getFormattedDate());
  terminal.println("The LEDs are on.");
  // turn the relay on
  digitalWrite(RELAYPIN, HIGH);
}

void stopRelay() {
  terminal.print(getFormattedDate());
  terminal.println("The LEDs are off.");
  // turn the relay off
  digitalWrite(RELAYPIN, LOW);
}
