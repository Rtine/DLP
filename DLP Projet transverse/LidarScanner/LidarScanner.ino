#include <Servo.h>
#include <LIDARLite.h>

Servo servoX;
Servo servoY;
LIDARLite lidar;

// Minimum et Maximum angle des servomoteurs en degrés
// Modifier pour éviter les limites imposées par la géométrie du support de panoramique / inclinaison
int minPosX = 0;
int maxPosX = 180;
int minPosY = 26;
int maxPosY = 125;

int buttonPin = 1;
int buttonValue = 1;
int buttonThreshold = 50;
int lastPosX = 0;
int lastPosY = 0;
int loopCount = 0;
int radius = 0;
int lastRadius = 0;
boolean selectButtonPressed = false;
boolean scanning = false;
boolean scanDirection = false;
int scanIncrement = 1;
int posX = (maxPosX + minPosX) / 2;
int posY = (maxPosY + minPosY) / 4;
float pi = 3.14159265;
float deg2rad = pi / 180.0;

void setup() {
  
  lidar.begin(0, true);
  lidar.configure(0);
  servoX.attach(2);
  servoY.attach(3);
  servoX.write(posX);
  servoY.write(posY);
  Serial.begin(9600);
}

void loop() {

  buttonValue = analogRead(buttonPin);

  if (scanning) {
    if (abs(buttonValue - 741) < buttonThreshold) {
      if (!selectButtonPressed) {
        // Change pour le mode de scan manuel
        selectButtonPressed = true;
        scanning = false;
        
      }
    } else {
      selectButtonPressed = false;
    }
    if (scanDirection) {
      posX += scanIncrement;
    } else {
      posX -= scanIncrement;
    }
    if (posX > maxPosX || posX < minPosX) {
      // Atteint la limite X, sens de balayage automatique inverse
      scanDirection = !scanDirection;
      posY += scanIncrement;
      if (posY > maxPosY) {
        // scan automatique terminé, retour au mode manuel
        scanning = false;
        
      }
    }
  } else {
    if (abs(buttonValue - 741) < buttonThreshold) {
      if (!selectButtonPressed) {
        // Change pour le mode de scan manuel
        selectButtonPressed = true;
        scanning = true;
        posX = minPosX;
        posY = minPosY;
        scanDirection = true;
        
      }
    } else if (abs(buttonValue - 505) < buttonThreshold) {
      // Scan manuel à gauche
      posX += 1;
    } else if (abs(buttonValue - 329) < buttonThreshold) {
      // Scan manuel en bas
      posY -= 1;
    } else if (abs(buttonValue - 145) < buttonThreshold) {
      // Scan manuel en haut
      posY += 1;
    } else if (abs(buttonValue - 0) < buttonThreshold) {
      // Scan manuel à droite
      posX -= 1;
    } else {
      selectButtonPressed = false;
    }
  }

  posX = min(max(posX, minPosX), maxPosX);
  posY = min(max(posY, minPosY), maxPosY);
  bool moved = moveServos();
  displayPosition();

  loopCount += 1;
  if (loopCount % 100 == 0) {
    // recalibrer le scanner toutes les 100 numérisations
    radius = lidar.distance();
  } else {
    radius = lidar.distance(false);
  }
  if (abs(radius - lastRadius) > 2)
  {
    lastRadius = radius;
  }
  if (scanning || moved) {
    float azimuth = posX * deg2rad;
    float elevation = (180 - maxPosY + posY) * deg2rad;
    double x = radius * sin(elevation) * cos(azimuth);
    double y = radius * sin(elevation) * sin(azimuth);
    double z = radius * cos(elevation);
    Serial.println(String(-x, 5) + " " + String(y, 5) + " " + String(-z, 5));
  }
}

bool moveServos()
{
  bool moved = false;
  static int lastPosX;
  static int lastPosY;
  int delta = 0;  
  if (posX != lastPosX) {
    delta += abs(posX - lastPosX);
    servoX.write(posX);
    lastPosX = posX;
    moved = true;
  }
  if (posY != lastPosY) {
    delta += abs(posY - lastPosY);
    servoY.write(posY);
    lastPosY = posY;
    moved = true;
  }
  delay(30);
  return moved;
}

void displayPosition()
{
  static int lastPosX;
  static int lastPosY;
  if (posX != lastPosX) {
    lastPosX = posX;
  }
  if (posY != lastPosY) {
    lastPosY = posY;
  }  
}
