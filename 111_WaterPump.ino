/***************************************************
 * Water pump
 * Pinout: GND and D34
 * 
 * Pumps water from the reservoir to the soil
 **************************************************/

// Instanciate a Chrono object.
Chrono waterpumpChrono; 
int waterpumpState = HIGH;

void setupWaterPump() {
  pinMode(WATERPIN, OUTPUT);
  digitalWrite(WATERPIN, HIGH);
}

void activateWaterPump() {
  if(waterpumpChrono.hasPassed(3000) ) { 
    waterpumpChrono.restart();
    if (waterpumpState==LOW) {
      terminal.print(getFormattedDate());
      terminal.println("The pump has stopped.");
      waterpumpState=HIGH;
    } else { 
      terminal.print(getFormattedDate());
      terminal.println(F("The pump has started."));
      waterpumpState=LOW;
    };
    // write the state to the pin
    digitalWrite(WATERPIN,waterpumpState);
  }
}
