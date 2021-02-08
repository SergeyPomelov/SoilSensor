#include <Functions.h>
#include <Constants.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

int moisture;
int vcc;
HTTPClient http;
WiFiClient wifi;

void readSensors() {
  digitalWrite(D7, HIGH);
  delay(300);
  moisture = analogRead(SOIL_PIN);
  Serial.print("Moisture : ");
  Serial.println(moisture);
  digitalWrite(D7, LOW);
}

void hibernate() {
  ESP.deepSleep(SLEEP_SEC * 1000U * 1000U);
}

void wait() {
  delay(SLEEP_SEC * 1000U);
}

boolean WiFiconnect()
{
  digitalWrite(LED_BUILTIN, HIGH);
  if (WiFi.status() != WL_CONNECTED && WiFi.SSID() != AP_SSID)
  {
    Serial.println(F("Initialising Wifi..."));
    WiFi.mode(WIFI_STA);
    WiFi.config(IP, GATE, MASK);
    WiFi.begin(AP_SSID, AP_PASS);
    WiFi.persistent(true);
    WiFi.setAutoConnect(true);
    WiFi.setAutoReconnect(true);
  }

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(200);
    Serial.print('.');
  }
  Serial.print(" Connected! IP address: ");
  Serial.println(WiFi.localIP());
  digitalWrite(LED_BUILTIN, LOW);
  return true;
}

void sendDataDomoticz() {

  if (WiFiconnect())
  {
    Serial.println("Domoticz send begin...\n");

    String url = "http://" + String(DOMOTICZ_IP) + ":" + DOMOTICZ_PORT + 
    "/json.htm?type=command&param=udevice&idx=199&nvalue=" + String(moisture) + "&svalue=" + String(moisture);
    http.begin(wifi, url);
    http.addHeader("Accept", "*/*");
    http.addHeader("Host", DOMOTICZ_IP);
    http.addHeader("Connection", "close");
    http.addHeader("Upgrade-Insecure-Requests", "1");
    http.addHeader("User-Agent", "ESP8266 We Mos 1 Plant Sensor");

    Serial.println((char*) url.c_str());
    int httpCode = http.GET();

    if (httpCode > 0) {
      Serial.printf("Domoticz send code: %d\n", httpCode);
      if (httpCode != HTTP_CODE_OK) {
        String payload = http.getString();
        Serial.println(payload);
      }
    } else {
      Serial.printf("Domoticz send failed, error: %s\n", http.errorToString(httpCode).c_str());
    }

    http.end();
  }
}
