#include <Constants.h>
#include <Functions.h>


void setup() {
  Serial.begin(9600);
  Serial.setTimeout(2000);
  Serial.setDebugOutput(true);
  Serial.println("setup");
  while (!Serial) { }


  pinMode(SOIL_PIN, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(D7, OUTPUT);
  pinMode(D0, WAKEUP_PULLUP);

  readSensors();
  sendDataDomoticz();
  hibernate();
}

void loop() {
}
