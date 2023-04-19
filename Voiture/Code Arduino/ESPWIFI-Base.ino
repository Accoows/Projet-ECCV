//
//  GitHub ESP8266: https://github.com/esp8266/Arduino
//  JSON ESP8266 Add: https://arduino.esp8266.com/stable/package_esp8266com_index.json
//  Blynk Library: https://github.com/blynkkk/blynk-library/releases/tag/v1.2.0
//  Blynk Docs: https://docs.blynk.io/en/
//  Docs install: https://www.gotronic.fr/pj2-35754-1803.pdf
//  Tools -> Board -> esp8266 -> NodeMC 1.0 (ESP-12E)
// 

#define BLYNK_PRINT Serial

//Library
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "TEST";

char ssid[] = "TESTT";
char pass[] = "TESTTTTT";

void setup()
{
    //none
}

void loop()
{
    Blynk.run()
}