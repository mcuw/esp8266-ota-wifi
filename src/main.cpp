#include <Arduino.h>
#include "./credentials.h"
#include <OTA.h>
#include <Telnet.h>

const char *ap_default_psk = AP_PSK; // Default PSK.

OTA ota;
Telnet telnet;

void setup()
{
  Serial.begin(115200);
  while (!Serial)
  {
  }
  Serial.println(F("\r\n"));

  ota.begin(ap_default_psk);
  telnet.begin();
}

void loop()
{
  ota.handle();
  telnet.handle();
}
