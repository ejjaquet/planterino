void setupHumidifier() {
  pinMode(ATOMPIN, OUTPUT);
}

void humidify() {
  digitalWrite(ATOMPIN, HIGH);   // atomize
  delay(10000);                  // wait for 10 seconds
  digitalWrite(ATOMPIN, LOW);    // atomization stopped
}
