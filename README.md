# ESP8266 OTA with WIFI

This template provides the OTA (over the air) feature of [ESP8266](https://www.espressif.com/en/products/socs/esp8266). The firmware is build with github actions based on the [ESP8266-ghbuild-template](https://github.com/mcuw/ESP32-ghbuild-template). You have to upload the firmware only once with the serial port.

## ESP-8266 dev board

Some development boards (ESP-201/ ESP-01/ ESP-07) are not able to use OTA because the flash size is too low: 512 KB

You need a memory upgrade for OTA, e.g.: 4 MB

Buy (affiliate link supports project w/o extra cost): [Windbond flash W25x40](https://s.click.aliexpress.com/e/_Dk3LwXJ)

New board configuration `esp-8266-4M2M` to allow OTA for sketches with  ~1019KB 
https://github.com/esp8266/Arduino/blob/master/tools/sdk/ld/eagle.flash.4m2m.ld

New board configuration `esp-8266-4M3M` to allow OTA for sketches with ~512KB 
https://github.com/esp8266/Arduino/blob/master/tools/sdk/ld/eagle.flash.4m3m.ld

## How to get the real flash informations

There is a scretch to check that you installed the flash successfully ...
For that uncomment `src_dir` in `platformio.ini`

```ini
src_dir = ./examples/real-memory
```

## Why should you want to use OTA?

Usually you can download a new firmware with the serial port.
In case you already placed your hardware into the target place then it can be difficult to remove it again.

Another use case is if you want a replacement of the serial cable and to flash the firmware wireless and without the cumbersome boot mode change with a switch. It is also much quicker with the WIFI speed to download a firmware.

Do you have another use case in mind? To be continued ...

## Get Started

copy configs and set up
```sh
cp upload_params_example.ini upload_params.ini
```

```sh
cp src/cred_example.h src/cred.h
```

## Links

Espressif: https://www.espressif.com/en/products/socs/esp8266

Wikipedia: https://en.wikipedia.org/wiki/ESP8266

readthedocs OTA: https://arduino-esp8266.readthedocs.io/en/latest/ota_updates/readme.html

Tutorials:

[Andreas Spiess - ESP32 OTA tutorial with tricks incl. OTA debugging](https://www.youtube.com/watch?v=1pwqS_NUG7Q)
How-To replace the flash: [Andreas Spiess - ESP-01/ESP-07 4Mbyte Memory Upgrade and OTA](https://www.youtube.com/watch?v=xyc1gCjguRU)
