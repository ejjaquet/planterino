# Planterino

Planterino is a indoor greenhouse, controlled by a set of Arduino sensors and actuators, connected to an Arduino Mega. All the sensor data is pushed to **Blynk**.

## Microcontroller

For the heart of the project a **Arduino Mega + WiFi** is used. Basically an Arduino Mega 2560 with a build-in ESP8266 WiFi chip. 
With the onboard jumpersettings you can controll the workings of the board:

Dip switch settins for Arduino Mega + Wifi:

    1=ON  2=ON  3=OFF 4=OFF 5=OFF 6=OFF 7=OFF 8=OFF (ATmega2560<->ESP8266)
    1=OFF 2=OFF 3=ON  4=ON  5=OFF 6=OFF 7=OFF 8=OFF (USB <->ATmega2560)
    1=OFF 2=OFF 3=OFF 4=OFF 5=ON  6=ON  7=ON  8=OFF (USB<->ESP8266 (Update firmware or sketch))
    1=OFF 2=OFF 3=OFF 4=OFF 5=ON  6=ON  7=OFF 8=OFF (USB<->ESP8266 (communication))
    1=OFF 2=OFF 3=OFF 4=OFF 5=OFF 6=OFF 7=OFF 8=OFF (All independent)

## Sensors

We use the following set of sensors to control the environment of the Planterino Greenhouse and to send the data to Blynk.

 - Capacitive Soil Moisture sensor
 - DHT22 Temperature sensor
 - SGP30 Air Quality sensor
 - Waterlevel sensor

## Actuators

We use the following set of actuator to influence the environment in the Planterino Greenhouse:

 - 5v waterpump
 - 5v fan (2x)
 - Grove Water Atomizer (Reichelt)
 - 12v Relay
 - Realtime Clock module

## Blynk
The data of the greenhouse is sent to Blynk.
With Blynk an app is created where you can read all data, turn on the light, pump, humidifier and fans, and control the treshhold settings.

## The greenhouse
The actual housing was copied from an idea found on YouTube:
[https://www.youtube.com/watch?v=1PAskxfDbow&list=WL&index=19&t=0s](https://www.youtube.com/watch?v=1PAskxfDbow&list=WL&index=19&t=0s)
Thanks to [Mr Useful](https://www.youtube.com/channel/UCb23xsrNokj8V6tv1g3nxeA) for creating that video.
