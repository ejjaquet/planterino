/***************************************************
 *        Global settings and pin definitions
 **************************************************/

// Hardware Serial on Mega, Leonardo, Micro...
#define EspSerial Serial3

// ESP8266 baud rate:
#define ESP8266_BAUD 115200

// Soil Moisture Sensor
#define MOISTUREPIN A6

// Water Pump (actuator)
#define WATERPIN 34

// Water level sensor
#define WATERLEVELPIN A7

// Fan
#define FAN1PIN 6

// DHT 22 sensor
#define DHTPIN 26
#define DHTTYPE DHT22

// Humidifier / Water Atomizer
#define ATOMPIN 23

// 12v relay for growth light
#define RELAYPIN 25
