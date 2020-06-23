/***************************************************
 * Water Atomization (Humidifier) 
 * Pinout: VCC, GND and D23
 * 
 * Start the atomization of a small amount of water to humidify
 **************************************************/

void setupHumidifier() {
  pinMode(ATOMPIN, OUTPUT);
}

void humidify() {
  terminal.print(getFormattedDate());
  terminal.println("The humidifier has started.");
  digitalWrite(ATOMPIN, HIGH);   // atomize
  delay(10000);                  // wait for 10 seconds
  terminal.print(getFormattedDate());
  terminal.println("The humidifier has stopped.");
  digitalWrite(ATOMPIN, LOW);    // atomization stopped
}
