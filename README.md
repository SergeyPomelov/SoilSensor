# SoilSensor
WiFi WeMos D1 Based Custom Soil Sensor Firmware.

![Soil Sensor](https://i.ibb.co/nmzfX2h/Soil.jpg)

![Repository Top Language](https://img.shields.io/github/languages/top/SergeyPomelov/SoilSensor)
![Languages](https://img.shields.io/github/languages/count/SergeyPomelov/SoilSensor)
![Github Repository Size](https://img.shields.io/github/repo-size/SergeyPomelov/SoilSensor)
![Github Open Issues](https://img.shields.io/github/issues/SergeyPomelov/SoilSensor)
![License](https://img.shields.io/badge/license-MIT-green)

### Build
The source code is verified to be compatible with [Platform IO](https://platformio.org/) and [Arduino IDE](https://www.arduino.cc/).

### Configure
- Setup in **Secret.h** your WiFi.  
- Change the data sending logic to your own. 
- Configure the deep sleep interval for power saving if you're running on battery. 
- You are done.

### Hardware
- [WeMos D1](https://docs.wemos.cc/en/latest/d1/index.html).
- Capacitive Soil Moisture Sensor V2.0. Or any for 3.3 or 5v, 3 Pin, produces analog output.

**Optional**
- [Battery Shield](https://docs.wemos.cc/en/latest/d1_mini_shiled/battery.html).
- [OLED Shield](https://docs.wemos.cc/en/latest/d1_mini_shiled/oled_0_66.html).
- [DHT Shield](https://docs.wemos.cc/en/latest/d1_mini_shiled/dht.html).
- [Ambient light Shield (BH1750)](https://docs.wemos.cc/en/latest/d1_mini_shiled/ambient_light.html).
- Generic 3.3V+ Battery with JST interface.
- Unparalleled LiPoFE4 or Li-Ion is recommended as the most effective source for most cases.
- For any additional sensors, just take note that WeMos's the only 1 analog port is busy.

# License
MIT License.
