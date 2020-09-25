#include <Functions.h>

int moisture;
HTTPClient http;

void readSensors() {
  moisture = analogRead(SOIL_PIN);
  Serial.print("Moisture : ");
  Serial.println(moisture);
}

void hibernate() {
  ESP.deepSleep(SLEEP_SEC * 1000000);
  // delay(SLEEP_SEC * 1000);
}

void wait() {
  delay(SLEEP_SEC * 1000);
}

void connectWiFi() {
  digitalWrite(LED_BUILTIN, HIGH);

  WiFi.mode(WIFI_STA);
  WiFi.begin(AP_SSID, AP_PASS);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print('.');
  }
  Serial.print(" Connected! IP address: ");
  Serial.println(WiFi.localIP());
  digitalWrite(LED_BUILTIN, LOW);
}

void sendData() {
  if ((WiFi.status() == WL_CONNECTED)) {
    Serial.println("Server send begin...\n");
    String content = String("{\r\n")
                     + "\"deviceId\": \"esp8266_soil_moisture\"" + ",\r\n"
                     + "\"moisture\": " +  String(moisture) + "\r\n}";


    http.begin("http://" + String(SERVER_IP) + ":" + SERVER_PORT + "/moisture");
    http.addHeader("Content-Type", "application/json");
    http.addHeader("Accept", "*/*");
    http.addHeader("Host", SERVER_IP);
    http.addHeader("Connection", "close");
    http.addHeader("Upgrade-Insecure-Requests", "1");
    http.addHeader("User-Agent", "ESP8266 We Mos 1");
    int httpCode = http.POST(content);

    if (httpCode > 0) {
      Serial.printf("Server send code: %d\n", httpCode);
      if (httpCode == HTTP_CODE_OK) {
        String payload = http.getString();
        Serial.println(payload);
      }
    } else {
      Serial.printf("Server send failed, error: %s\n", http.errorToString(httpCode).c_str());
    }

    http.end();
  }
}

void sendDataDomoticz() {
  if ((WiFi.status() == WL_CONNECTED)) {
    Serial.println("Domoticz send begin...\n");

    char charBuf[50];
    String url = "http://" + String(DOMOTICZ_IP) + ":" + DOMOTICZ_PORT + "/json.htm?type=command&param=udevice&idx=199&nvalue=" 
    + String(moisture) + "&svalue=" + String(moisture) + "&passcode=1lots!APOqs";
    http.begin(url);
    http.addHeader("Accept", "*/*");
    http.addHeader("Host", DOMOTICZ_IP);
    http.addHeader("Connection", "close");
    http.addHeader("Upgrade-Insecure-Requests", "1");
    http.addHeader("User-Agent", "ESP8266 We Mos 1");
    http.addHeader("Authorization", DOMOTICZ_AUTH);

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
