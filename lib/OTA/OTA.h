#ifndef OTA_H
#define OTA_H

#define HOSTNAME "ESP8266-" // Hostname prefix and the Chip ID will be added at the end

class OTA
{
public:
  OTA();
  virtual ~OTA(){};

  void begin(const char *password, const char *station_ssid = "", const char *station_psk = "");
  void handle();

private:
  void startAP(const char *password);
  boolean startSTA(const char *station_ssid, const char *station_psk, const char *password);
  String setHostname();
};

#endif