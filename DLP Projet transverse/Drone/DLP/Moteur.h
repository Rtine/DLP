
  /* Le moteur permet au drone d'avancer, de faire demi-tour, tourner à gauche ou encore tourner à droite. Ici, nous allons programmer cela afin que notre drone terrestre puisse faire les actions
   *  énoncés précédemment en prenant en compte que par la suite nous allons affecter ses valeurs à l'aide de bouton*/


void GoStraightAhead()
{
  digitalWrite(D0_MOTOR_G_1,HIGH);
  digitalWrite(D0_MOTOR_G_2,LOW);  
 
  
  digitalWrite(D0_MOTOR_G_EN,HIGH);
  
  
  DroneStop = false;   

}


void Stop()
{
  digitalWrite(D0_MOTOR_G_1,LOW);
  digitalWrite(D0_MOTOR_G_2,LOW);  
  
  
  digitalWrite(D0_MOTOR_G_EN,LOW);
 
  
  DroneStop = true;  
  
}


void TurnLeft()
{
  digitalWrite(D0_MOTOR_G_1,LOW);
  digitalWrite(D0_MOTOR_G_2,HIGH);  
  
  
  digitalWrite(D0_MOTOR_G_EN,HIGH);
  
  
  delay(DurationTurn);
  
  digitalWrite(D0_MOTOR_G_EN,LOW);
 
  
  digitalWrite(D0_MOTOR_G_1,LOW);
  digitalWrite(D0_MOTOR_G_2,LOW);  
 
  
  DroneStop = true;  
  
}


void TurnRight()
{
  digitalWrite(D0_MOTOR_G_1,HIGH);
  digitalWrite(D0_MOTOR_G_2,LOW);  
 
  
  delay(DurationTurn);
  
  digitalWrite(D0_MOTOR_G_EN,LOW);

  
  digitalWrite(D0_MOTOR_G_1,LOW);
  digitalWrite(D0_MOTOR_G_2,LOW);  
 
  
  DroneStop = true; 
   
}


void TurnAround()
{
  digitalWrite(D0_MOTOR_G_1,HIGH);
  digitalWrite(D0_MOTOR_G_2,LOW);  
  
  digitalWrite(D0_MOTOR_G_EN,HIGH);
  
  
  delay(DurationTurnAround);
  
  digitalWrite(D0_MOTOR_G_EN,LOW);
 
  digitalWrite(D0_MOTOR_G_1,LOW);
  digitalWrite(D0_MOTOR_G_2,LOW);  
  
  
  DroneStop = true;  

}

   
