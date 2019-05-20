
  /* Fonction permettant l'initialisation du programme, équivalent du void setup lors d'une programation */

void Initialisation() 
  {
    pinMode(D0_MOTOR_G_1, OUTPUT);
    digitalWrite(D0_MOTOR_G_1, LOW);
    pinMode(D0_MOTOR_G_2, OUTPUT);
    digitalWrite(D0_MOTOR_G_2, LOW);
            
    digitalWrite(D0_MOTOR_G_EN,LOW); /// EN = Enable

    LeServo.attach(DIGITAL);

    StraightAhead();

  }
