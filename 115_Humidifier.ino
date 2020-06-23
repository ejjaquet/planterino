/***************************************************
 * Water Atomization (Humidifier) 
 * Pinout: VCC, GND and D23
 * 
 * Start the atomization of a small amount of water to humidify
 **************************************************/

// Instanciate a Chrono object.
Chrono humidifierChrono; 
int humidifierState = LOW;

void setupHumidifier() {
  pinMode(ATOMPIN, OUTPUT);
}

void activateHumidifier() {
  if(humidifierChrono.hasPassed(10000) ) { 
    humidifierChrono.restart();
    if (humidifierState==HIGH) {
      terminal.print(getFormattedDate());
      terminal.println("The humidifier has stopped.");
      humidifierState=LOW;
    } else { 
      terminal.print(getFormattedDate());
      terminal.println("The humidifier has started.");
      humidifierState=HIGH;
    };
    // write the state to the pin
    digitalWrite(ATOMPIN,humidifierState);
  }
}
