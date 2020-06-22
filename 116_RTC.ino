RTC_DS3231 rtc;

int hourThresholdOn = 15;
int minuteThresholdOn = 18;

int hourThresholdOff = 15;
int minuteThresholdOff = 19;

void setupRTC() {
  Wire.begin();
  rtc.begin();
  // rtc.adjust(DateTime(F(__DATE__),F(__TIME__)));
}

void checkTime() {
  DateTime now = rtc.now();
  Serial.print("Time: ");
  Serial.print(now.hour());
  Serial.print("h ");
  Serial.print(now.minute());
  Serial.println("m");

  if(now.hour() == hourThresholdOn && now.minute() == minuteThresholdOn)
    {
       // turn the relay on
       digitalWrite(RELAYPIN, HIGH);
    }

    if(now.hour() == hourThresholdOff && now.minute() == minuteThresholdOff)
    {
       // turn the relay off
       digitalWrite(RELAYPIN, LOW);
    }
    
}
