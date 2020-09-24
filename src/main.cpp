#include <Functions.h>

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(2000);
  Serial.setDebugOutput(true);
  while (!Serial) { }
  
  pinMode(BUILTIN_LED, OUTPUT);
  pinMode(D0, WAKEUP_PULLUP);

  connectWiFi();
  readSensors();
  // sendData();
  sendDataDomoticz();
  hibernate();
}

void loop() {

}
