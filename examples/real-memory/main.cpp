#include <Arduino.h>

void setup()
{
  Serial.begin(115200);
  while (!Serial)
  {
  }
  Serial.println(F("\r\n"));

  delay(1000);

  uint32_t realSize = ESP.getFlashChipRealSize();
  uint32_t ideSize = ESP.getFlashChipSize();
  FlashMode_t ideMode = ESP.getFlashChipMode();

  Serial.printf("Flash real id:   %08X\n", ESP.getFlashChipId());
  Serial.printf("Flash real size: %u bytes\n\n", realSize);
  Serial.printf("Flash ide  size: %u bytes\n", ideSize);
  Serial.printf("Flash ide speed: %u Hz\n", ESP.getFlashChipSpeed());
}

void loop()
{
  delay(1000);
}
