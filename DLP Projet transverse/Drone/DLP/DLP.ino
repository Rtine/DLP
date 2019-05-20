#include <Servo.h>
#include "Arduino.h"
#include "Affectation_E_S.h"
#include "Configuration.h"
#include "Moteur.h"
#include "ServoMoteur.h"
#include "Initialisation.h"

  /* Déclaration de la variable clear */

char destroy;

  /* Déclaration du String permettant d'interargir avec les boutons des applications Bureautique et Mobile */
  
String inputString="";  


void setup() {
  Serial.begin(9600);
  pinMode(D0_MOTOR_G_1,OUTPUT);
  pinMode(D0_MOTOR_G_2,OUTPUT);

  LeServo.attach(DIGITAL);

}

void loop() {
  if(Serial.available()){
  while(Serial.available())
    {
      char inChar = (char)Serial.read(); /* Permet de lire la valeur du bouton */
      inputString += inChar;        /* Permet de faire une chaîne de caractères à venir en série */
    }
    Serial.println(inputString);
    while (Serial.available() > 0)  
    { destroy = Serial.read() ; }      /* Permet de détruire le buffer (c'est-à-dire rien ne se passe si on ne touche à rien) */
    if(inputString == "a"){         /* Dans la case "a" nous indiquons d'aller devant */
     GoStraightAhead();                                                  
    }else if(inputString == "s"){   /* Dans la case "s" nous indiquons au Drone de s'arrêter */
      Stop();                         
    }
    else if(inputString == "g"){    /* Dans la case "a" nous indiquons d'aller à gauche */
      Left();
      TurnLeft();                        
    }
    else if(inputString == "d"){   /* Dans la case "a" nous indiquons d'aller à droite */
      Right();
      TurnRight();                          
    }
    inputString = "";
  }

}
