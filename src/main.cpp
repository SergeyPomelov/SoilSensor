#include <Constants.h>
#include <Functions.h>


void setup() {
  Serial.begin(76800);
  Serial.setTimeout(2000);
  Serial.setDebugOutput(true);
  Serial.println("setup");
  while (!Serial) { }

  pinMode(SOIL_PIN, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(SOIL_PWR, OUTPUT);
  pinMode(WAKEUP, WAKEUP_PULLUP);

  readSensors();
  // sendDataDomoticz();
  hibernate();
}

void loop() {
  Serial.println("loop");
  //readSensors();
  //delay(1000);
}
