
  /* Liste des configuration pour le bon fonctionnement du programme */

/* Servomoteur */

int Position_I_DuServo = 90;   /// Position Initiale, en degré
int Position_G_DuServo = 175;  /// Position du ServoMoteur qui regarde à gauche, en degré
int PositioningServo   = 250;  /// Durée d'attente en milliseconde pour que le ServoMoteur ai atteint sa position 

    /* Moteur */

boolean DroneStop      = true; /// Variable permettant de voir l'état "arrêt" du drone
int DurationTurn       = 250;  /// Durée d'une rotation horaire ou anti-horaire du drone 
int DurationTurnAround = 550;  /// Durée d'un demi-tour du drone
