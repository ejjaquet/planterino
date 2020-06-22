void setupHumidifier() {
  pinMode(ATOMPIN, OUTPUT);
}

void humidify() {
  Serial.println("Starting humidifier...");
  digitalWrite(ATOMPIN, HIGH);   // atomize
  delay(10000);                  // wait for 10 seconds
  digitalWrite(ATOMPIN, LOW);    // atomization stopped
}
