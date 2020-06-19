ESP8266 wifi(&EspSerial);

BlynkTimer timer;

void myTimerEvent()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Serial.println("Ik ga sturen");
  Blynk.virtualWrite(V1, millis() / 1000);
}
