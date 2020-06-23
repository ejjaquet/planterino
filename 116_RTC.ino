/***************************************************
 * Real Time Clock module
 * Pinout: SDA, SCL, VCC and ground
 * 
 * Keeps the time and schedule for the lights
 **************************************************/

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

String getFormattedDate() {
  DateTime now = rtc.now();
  return now.timestamp(DateTime::TIMESTAMP_FULL)+String(": ");
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
       terminal.println("The LEDs are on.");
       // turn the relay on
       digitalWrite(RELAYPIN, HIGH);
    }

    if(now.hour() == hourThresholdOff && now.minute() == minuteThresholdOff)
    {
       terminal.println("The LEDs are off.");
       // turn the relay off
       digitalWrite(RELAYPIN, LOW);
    }
    
}
