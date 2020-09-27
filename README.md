# SoilSensor
WiFi WeMos D1 Based Custom Soil Sensor Firmware.

![Soil Sensor](https://i.ibb.co/nmzfX2h/Soil.jpg)

### Build
The source code is verified to be compatible with [Platform IO](https://platformio.org/) and [Arduino IDE](https://www.arduino.cc/).

### Configure
- Setup in **Secreth.h** your own WiFi.  
- Change the data sending logic to your own. 
- Configure the deep sleep interval for power saving if you're running on battery. 
- You are done.

### Hardware
- [WeMos D1](https://docs.wemos.cc/en/latest/d1/index.html).
- Capacitive Soil Moisture Sensor V2.0. Or any for 3.3 or 5v, 3 Pin, produces analogue output.

**Optional**
- [Battery Shiled](https://docs.wemos.cc/en/latest/d1_mini_shiled/battery.html).
- [OLED Shield](https://docs.wemos.cc/en/latest/d1_mini_shiled/oled_0_66.html).
- [DHT Shield](https://docs.wemos.cc/en/latest/d1_mini_shiled/dht.html).
- [Ambient light Shield (BH1750)](https://docs.wemos.cc/en/latest/d1_mini_shiled/ambient_light.html).
- Generic 3.3V+ Battery with JST interface.
- Unparalleled LiPoFE4 or Li Ion recommended as the most effective sources for most cases.
- Any additional sensors, just take a note that WeMos's the only 1 analogue port is busy.

### Wiring without shields
![Wiring](https://i.ibb.co/MBx5dF0/soil-Sensor-Wiring.jpg)

# License
MIT License.
