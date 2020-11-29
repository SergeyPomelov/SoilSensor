#include <Constants.h>
#include <Functions.h>

ADC_MODE(ADC_VCC);


void setup() {
  Serial.begin(9600);
  Serial.setTimeout(2000);
  Serial.setDebugOutput(true);
  while (!Serial) { }

  pinMode(SOIL_PIN, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(D0, WAKEUP_PULLUP);

  WiFiconnect();
  readSensors();
  sendDataDomoticz();
  hibernate();
}

void loop() {

}
