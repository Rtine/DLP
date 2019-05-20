
  /* Ici, nous allons configurer le "radar" du drone, en effet, nous avons configurer précedemment le capteur ultrasonor afin qu'il puisse détecter un obstacle, mais une fois que l'obstacle
   *  est détecter et que le drone est à l'arrêt, le drone doit être capable de trouver une issue, par conséquent, il doit voir si à gauche ou à droite une issue est possible. D'où le capteur
   *  capteur ultrasonor doit être capable de voir en 180°. Le programme ici sera rempli de fonction concernant le programme principale  */


Servo LeServo;


void StraightAhead(){
  
  LeServo.write(Position_I_DuServo);

  delay(15); /// Sécurité, pour savoir si le servomoteur ai le temps d'atteindre sa position initiale
    
}


void Left(){

  LeServo.write(Position_G_DuServo);

  delay(PositioningServo);      
      
}


void Right(){

  LeServo.write(Position_G_DuServo);

  delay(PositioningServo);
  
}
