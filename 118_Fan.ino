/***************************************************
 * 5 volt Fan
 * Pinout: Ground and D6
 * 
 * Fan to be turned on and off by Co2 sensor
 **************************************************/

// Instanciate a Chrono object.
Chrono fanChrono; 
int fanState = LOW;

void setupFan() {
  pinMode(FAN1PIN, OUTPUT);
  digitalWrite(FAN1PIN, LOW);
  pinMode(FAN2PIN, OUTPUT);
  digitalWrite(FAN2PIN, LOW);
}

void activateFan() {
  if(fanChrono.hasPassed(10000) ) { 
    fanChrono.restart();
    if (fanState==HIGH) {
      terminal.print(getFormattedDate());
      terminal.println("The fan has stopped.");
      fanState=LOW;
    } else { 
      terminal.print(getFormattedDate());
      terminal.println("The fan has started.");
      fanState=HIGH;
    };
    // write the state to the pin
    digitalWrite(FAN1PIN,fanState);
    digitalWrite(FAN2PIN,fanState);
  }
}
