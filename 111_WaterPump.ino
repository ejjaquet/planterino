void setupWaterPump() {
  pinMode(WATERPIN, OUTPUT);
  digitalWrite(WATERPIN, LOW);
}

void startPump() {
  digitalWrite(WATERPIN, HIGH);
}

void stopPump() {
  digitalWrite(WATERPIN, LOW);
}

void waterPlants() {
  startPump();
  delay(3000);
  stopPump();
}
