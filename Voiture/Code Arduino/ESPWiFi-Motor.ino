//
//  GitHub ESP8266: https://github.com/esp8266/Arduino
//  ESP8266 Docs: https://arduino-esp8266.readthedocs.io/en/3.1.2/index.html
//  JSON ESP8266 Add: https://arduino.esp8266.com/stable/package_esp8266com_index.json
//  Blynk Library: https://github.com/blynkkk/blynk-library/releases/tag/v1.2.0
//  Blynk Docs: https://docs.blynk.io/en/
//  Docs install: https://www.gotronic.fr/pj2-35754-1803.pdf
//  Tools -> Board -> esp8266 -> NodeMC 1.0 (ESP-12E)
// 

// Network Blynk.Cloud
#define BLYNK_TEMPLATE_ID "TMPL59chUkpoO"
#define BLYNK_TEMPLATE_NAME "ECCV Control"
#define BLYNK_AUTH_TOKEN "PNC5dJ6PvogE40Ot8ako4nH2oXmiATlx"
#define BLYNK_PRINT Serial

//Library WiFi/Blynk
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

//Auth TOKEN Blynk
char auth[] = BLYNK_AUTH_TOKEN;

//Connection WiFi
char ssid[] = "ECCV-Control";
char pass[] = "ECCV01234";

// Motor PIN Direction
//      TEST
//Motor A
#define D12 4  // Direction A (GPIO4 - D2)
#define D3 0   // PWM Motor A (GPIO0 - D3)
#define D9 2   // Brake Motor A (GPIO2 - D4)
//Motor B
#define D13 12 // Direction B (GPIO12 - D6)
#define D11 13 // PWN Motor B (GPIO13 - D7)
#define D8 15  // Brake Motor B (GPIO15 - D8)

//Code
void setup()
{
    //none
}

void loop()
{
    Blynk.run()
}