/***************************************************
 * Water pump
 * Pinout: GND and D34
 * 
 * Pumps water from the reservoir to the soil
 **************************************************/

// Instanciate a Chrono object.
Chrono waterpumpChrono; 
int waterpumpState = LOW;

void setupWaterPump() {
  pinMode(WATERPIN, OUTPUT);
  digitalWrite(WATERPIN, LOW);
}

void activateWaterPump() {
  if(waterpumpChrono.hasPassed(3000) ) { 
    waterpumpChrono.restart();
    if (waterpumpState==HIGH) {
      terminal.print(getFormattedDate());
      terminal.println("The pump has stopped.");
      waterpumpState=LOW;
    } else { 
      terminal.print(getFormattedDate());
      terminal.println(F("The pump has started."));
      waterpumpState=HIGH;
    };
    // write the state to the pin
    digitalWrite(WATERPIN,waterpumpState);
  }
}
