/***************************************************
 * Water pump
 * Pinout: GND and D34
 * 
 * Pumps water from the reservoir to the soil
 **************************************************/

void setupWaterPump() {
  pinMode(WATERPIN, OUTPUT);
  digitalWrite(WATERPIN, LOW);
}

void startPump() {
  terminal.print(getFormattedDate());
  terminal.println(F("The pump has started."));
  digitalWrite(WATERPIN, HIGH);
}

void stopPump() {
  terminal.print(getFormattedDate());
  terminal.println("The pump has stopped.");
  digitalWrite(WATERPIN, LOW);
}

void waterPlants() {
  startPump();
  delay(3000);
  stopPump();
}
