#include <Arduino.h>
#include <TelnetStream.h>
#include "../../src/credentials.h"
#include <OTA.h>

const char *ap_default_psk = AP_PSK; // Default PSK.

OTA ota;

void setup()
{
  Serial.begin(115200);
  while (!Serial)
  {
  }
  Serial.println(F("\r\n"));
  Serial.println(F("TELNET example"));

  ota.begin(ap_default_psk);
  TelnetStream.begin();
}

void log()
{
  static int i = 0;
  TelnetStream.println(i++);

  // TelnetStream.print("A0: ");
  // TelnetStream.println(analogRead(A0));
}

void loop()
{
  ota.handle();

  switch (TelnetStream.read())
  {
  case 'r':
    TelnetStream.println("RESET");
    TelnetStream.stop();
    delay(100);
    ESP.reset();
    break;
  case 'q':
    TelnetStream.println("bye bye");
    TelnetStream.flush();
    TelnetStream.stop();
    break;
  }

  static unsigned long next;
  if (millis() - next > 5000)
  {
    next = millis();
    log();
  }
}
