DHT dht(DHTPIN, DHTTYPE, 15);

float h;                      // value for humidity reading
float t;                      // value for temperature reading
float hic;                    // value for calculated heat index
int   humidityThreshold = 5; // value when to turn on humidifier


void setupDHT22() {
  dht.begin();
}

void readTemp() {
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  t = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Compute heat index in Celsius (isFahreheit = false)
  hic = dht.computeHeatIndex(t, h, false);

  if(hic < humidityThreshold) {
    humidify();
  }

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.println("%");
  Serial.print(F("Temperature: "));
  Serial.print(t);
  Serial.println("°C");
  Serial.print(F("Heat index: "));
  Serial.print(hic);
  Serial.println(F("°C "));
}
