#include <Arduino.h>
#include <ESP8266WiFi.h>

void setup()
{
  Serial.begin(115200);
  while (!Serial)
  {
  }
}

void loop()
{
  Serial.println("Hello ESP8266");
  delay(1000);
}
