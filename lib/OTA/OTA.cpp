#include <ArduinoOTA.h>
#include <ESP8266WiFi.h>
#include "./OTA.h"

OTA::OTA()
{
}

String OTA::setHostname()
{
  String hostname(HOSTNAME);
  hostname += String(ESP.getChipId(), HEX);
  WiFi.hostname(hostname);
  // Serial.println("Hostname: " + hostname);
  return hostname;
}

void OTA::startAP(const char *password)
{
  String hostname(setHostname());

  // Go into software AP mode.
  WiFi.mode(WIFI_AP);
  delay(10);
  WiFi.softAP(hostname, password);

  Serial.print(F("AP IP address: "));
  Serial.println(WiFi.softAPIP());

  // Start OTA server.
  ArduinoOTA.setHostname(hostname.c_str());
  ArduinoOTA.setPassword(password);
  ArduinoOTA.begin();
}

boolean OTA::startSTA(const char *station_ssid, const char *station_psk, const char *password)
{
  if (strcmp(station_ssid, "") == 0 || strcmp(station_psk, "") == 0)
  {
    return false;
  }

  String hostname(setHostname());

  // Check Wifi mode
  if (WiFi.getMode() != WIFI_STA)
  {
    WiFi.mode(WIFI_STA);
    delay(10);
  }

  // Compare file config with sdk config
  if (strcmp(WiFi.SSID().c_str(), station_ssid) == 0 && strcmp(WiFi.psk().c_str(), station_psk) == 0)
  {
    // Begin with sdk config
    WiFi.begin();
  }
  else
  {
    Serial.println(F("WiFi config changed"));

    // Connect to WiFi station
    WiFi.begin(station_ssid, station_psk);

    Serial.print(F("New SSID: "));
    Serial.println(WiFi.SSID());
  }

  Serial.println(F("Wait for WiFi connection."));

  // Give ESP 10 seconds to connect to station
  unsigned long startTime = millis();
  while (WiFi.status() != WL_CONNECTED && millis() - startTime < 10000)
  {
    Serial.print(".");
    // Serial.print(WiFi.status());
    delay(500);
  }
  Serial.println();

  // Check connection
  if (WiFi.status() != WL_CONNECTED)
  {
    Serial.println(F("Failed to connect to WiFi station"));
    return false;
  }

  // print IP Address
  Serial.print(F("STA IP address: "));
  Serial.println(WiFi.localIP());

  // Start OTA server.
  ArduinoOTA.setHostname(hostname.c_str());
  ArduinoOTA.setPassword(password);
  ArduinoOTA.begin();

  return true;
}

void OTA::begin(const char *password, const char *station_ssid, const char *station_psk)
{
  if (!startSTA(station_ssid, station_psk, password))
  {
    startAP(password);
  }
}

void OTA::handle()
{
  ArduinoOTA.handle();
}
