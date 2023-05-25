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
#define directionPin_A 4    // Direction A (GPIO4 - D2) (Shield_D12)
#define speedMotor_A 0      // (Speed) PWM Motor A (GPIO0 - D3) (Shield_D3)
#define brakeMotor_A 2      // Brake Motor A (GPIO2 - D4) (Shield_D9)
//Motor B
#define directionPin_B 12   // Direction B (GPIO12 - D6) (Shield_D13)
#define speedMotor_B 13     // (Speed) PWN Motor B (GPIO13 - D7) (Shield_D11)
#define brakeMotor_B 15     // Brake Motor B (GPIO15 - D8)  (Shield_D8)


//Code
void setup()
{
    //Configure Pins
    pinMode(directionPin_A, OUTPUT);
    pinMode(directionPin_B, OUTPUT);
    pinMode(speedMotor_A, OUTPUT); //(ENA - PWM)
    pinMode(speedMotor_B, OUTPUT); //(ENB - PWM)
    pinMode(brakeMotor_A, OUTPUT);
    pinMode(brakeMotor_B, OUTPUT);

    // Speed off
    digitalWrite(speedMotor_A, LOW);
    digitalWrite(speedMotor_B, LOW);

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
//  Serial.print("Speed Gauche: ");
//  Serial.println(speedGauche); //Affichage valeur G
  if (speedGauche > 500) {                              //Forward G
    analogWrite(speedMotor_B,speedGauche);
    digitalWrite(directionPin_B,HIGH);
    digitalWrite(brakeMotor_B,LOW);
  }
  else if (speedGauche < -500) {                        //Backward G
    analogWrite(speedMotor_B,-speedGauche);
    digitalWrite(directionPin_B,LOW);
    digitalWrite(brakeMotor_B,LOW);
  }
  else {                                                //Stop
    analogWrite(speedMotor_B, 0);
    digitalWrite(brakeMotor_B,HIGH);
  }
}

// SLIDER CONTROLER DROITE
BLYNK_WRITE(V1) {
  int speedDroit = param.asInt(); // lecture slider droit (Vérifier le [])
//  Serial.print("Speed Droit: ");
//  Serial.println(speedDroit); //Affichage valeur D
  if (speedDroit > 500) {                               //Forward D
    analogWrite(speedMotor_A,speedDroit);
    digitalWrite(directionPin_A,LOW);
    digitalWrite(brakeMotor_A,LOW);
  }
  else if (speedDroit < -500) {                         //Backward D
    analogWrite(speedMotor_A,-speedDroit);
    digitalWrite(directionPin_A,HIGH);
    digitalWrite(brakeMotor_A,LOW);
  }
  else {                                                //Stop
    analogWrite(speedMotor_A, 0);
    digitalWrite(brakeMotor_A,HIGH);
  }
}

//Démarrage du système Blynk
void loop()
{
    BlynkEdgent.run();
}