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

//Librairi Wifi/Blynk
#include "BlynkEdgent.h"

// Initilisation et création d'un wifi local

// Motor PIN - L298N

//Motor A (Gauche)
#define ENA 4                // Pin ENA (GPIO4 - D2) (PWM A)
#define speedMotor_A1 5      // Speed Motor A1 (GPIO5 - D1) (IN1)
#define speedMotor_A2 16     // Speed Motor A2 (GPIO16 - D0) (IN2)

//Motor B (Droite)
#define ENB 12               // Pin ENB (GPIO12 - D6) (PWM B)
#define speedMotor_B1 13     // Speed Motor B1 (GPIO13 - D7) (IN3)
#define speedMotor_B2 15     // Speed Motor B2 (GPIO15 - D8)  (IN4)


// Code
// Initialisation des variables de sorties ESP8266 -> L298N
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
    
    //Serial communication
    Serial.begin(115200);

    //Connect Blynk Statut
    BlynkEdgent.begin();
}

// SLIDER CONTROLER GAUCHE
BLYNK_WRITE(V0) {
  int speedGauche = param.asInt();                      // Lecture slider Gauche
  Serial.print("Speed Gauche: ");
  Serial.println(speedGauche);
  
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
  int speedDroit = param.asInt();                       // Lecture slider Droit
  Serial.print("Speed Droit: ");
  Serial.println(speedDroit);

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