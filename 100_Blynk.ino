ESP8266 wifi(&EspSerial);

String BlynkServer = "blynk-cloud.com";
BlynkTimer timer;

void heartBeatPrint(void) {
  static int num = 1;

  if (Blynk.connected()) {
    Serial.print("B");
  } else {
    Serial.print("F");
  }

  if (num == 80) {
    Serial.println();
    num = 1;
  } else if (num++ % 10 == 0) {
    Serial.print(" ");
  }
}

void check_status() {
  static unsigned long checkstatus_timeout = 0;

  #define STATUS_CHECK_INTERVAL     15000L

  // Send status report every STATUS_REPORT_INTERVAL (60) seconds: we don't need to send updates frequently if there is no status change.
  if ((millis() > checkstatus_timeout) || (checkstatus_timeout == 0)) {
    // report status to Blynk
    heartBeatPrint();
    checkstatus_timeout = millis() + STATUS_CHECK_INTERVAL;
  }
}
