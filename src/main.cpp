#include <Arduino.h>
#include "./cred.h"
#include "./OTA.h"

const char *ap_default_psk = AP_PSK; // Default PSK.

OTA ota;

void setup()
{
  Serial.begin(115200);
  while (!Serial)
  {
  }
  Serial.println(F("\r\n"));

  ota.begin(ap_default_psk);
}

void loop()
{
  ota.handle();
}
