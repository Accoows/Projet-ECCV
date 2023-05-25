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
#define BLYNK_FIRMWARE_VERSION "0.1.2"
#define BLYNK_PRINT Serial
#define APP_DEBUG

//Library WiFi/Blynk
#include "BlynkEdgent.h"

// Motor PIN Direction
//      TEST

//Motor A
#define ENA 4               // Direction A (GPIO4 - D2) (Shield_D12)
#define speedMotor_A1 5      // (Speed) PWM Motor A (GPIO0 - D1) (Shield_D3)
#define speedMotor_A2 16      // Brake Motor A (GPIO2 - D0) (Shield_D9)
//Motor B
#define ENB 12   // Direction B (GPIO12 - D6) (Shield_D13)
#define speedMotor_B1 13     // (Speed) PWN Motor B (GPIO13 - D7) (Shield_D11)
#define speedMotor_B2 15     // Brake Motor B (GPIO15 - D8)  (Shield_D8)


//Code
void setup()
{
    //Configure Pins
    pinMode(ENA, OUTPUT); //(ENA - PWM)
    pinMode(ENB, OUTPUT); //(ENB - PWM)
    pinMode(speedMotor_A1, OUTPUT);
    pinMode(speedMotor_A2, OUTPUT);
    pinMode(speedMotor_B1, OUTPUT);
    pinMode(speedMotor_B2, OUTPUT);

    // Speed off
    digitalWrite(ENA, LOW);
    digitalWrite(ENB, LOW);

    Blynk.virtualWrite(V0, 0);
    Blynk.virtualWrite(V1, 0);
    
    //Serial communication
    Serial.begin(115200);

    //Connect Blynk Statut
    BlynkEdgent.begin();
}

// SLIDER CONTROLER GAUCHE
BLYNK_WRITE(V0) {
  int speedGauche = param.asInt(); // lecture slider gauche (Vérifier le [])
  Serial.print("Speed Gauche: ");
  Serial.println(speedGauche); //Affichage valeur G
  if (speedGauche > 500) {                              //Forward G
    analogWrite(ENA, speedGauche);
    digitalWrite(speedMotor_A1, LOW);
    digitalWrite(speedMotor_A2, HIGH);
  }
  else if (speedGauche < -500) {                        //Backward G
    analogWrite(ENA,-speedGauche);
    digitalWrite(speedMotor_A1, HIGH);
    digitalWrite(speedMotor_A2, LOW);
  }
  else {                                                //Stop
    analogWrite(ENA, LOW);
    digitalWrite(speedMotor_A1, LOW);
    digitalWrite(speedMotor_A2, LOW);
  }
}

// SLIDER CONTROLER DROITE
BLYNK_WRITE(V1) {
  int speedDroit = param.asInt(); // lecture slider droit (Vérifier le [])
  Serial.print("Speed Droit: ");
  Serial.println(speedDroit); //Affichage valeur D
  if (speedDroit > 500) {                               //Forward D
    analogWrite(ENB, speedDroit);
    digitalWrite(speedMotor_B1, HIGH);
    digitalWrite(speedMotor_B2, LOW);
  }
  else if (speedDroit < -500) {                         //Backward D
    analogWrite(ENB, -speedDroit);
    digitalWrite(speedMotor_B1, LOW);
    digitalWrite(speedMotor_B2, HIGH);
  }
  else {                                                //Stop
    analogWrite(ENB, LOW);
    digitalWrite(speedMotor_B1, LOW);
    digitalWrite(speedMotor_B2, LOW);
  }
}

//Démarrage du système Blynk
void loop()
{
    BlynkEdgent.run();
}