#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>
#include <Servo.h> 

// assign all the names of the servos
Servo Fr;
Servo Fl;
Servo Br;
Servo Bl;

// all of the functions needed for "Walley" to function
void forward(){Fr.writeMicroseconds(1000); Fl.writeMicroseconds(2000); Br.writeMicroseconds(1000); Bl.writeMicroseconds(2000);}  // function to move the robot forward
void backward(){Fr.writeMicroseconds(2000); Fl.writeMicroseconds(1000); Br.writeMicroseconds(2000); Bl.writeMicroseconds(1000);} // function to move the robot backward
void right(){Fr.writeMicroseconds(1500); Fl.writeMicroseconds(2000); Br.writeMicroseconds(1500); Bl.writeMicroseconds(1000);}    // function to turn the robot right
void left() {Fr.writeMicroseconds(1000); Fl.writeMicroseconds(1500); Br.writeMicroseconds(1000); Bl.writeMicroseconds(1500);}    // function to turn the robot left
void stop(){Fr.writeMicroseconds(1500); Fl.writeMicroseconds(1500); Br.writeMicroseconds(1500); Bl.writeMicroseconds(1500);}     // function to stop the robot
void spray(){digitalWrite(3, HIGH); delay(100); digitalWrite(3, LOW);}                                                                                 // function to spray the cleaning solution
void clean(){ spray(); delay(100); forward(); delay(2500); spray(); delay(100); forward(); delay(2500); right(); delay(1000); forward(); delay(1000); right(); delay(1000); spray(); delay(100); forward(); delay(5000);} // function for automatic cleaning

void setup() {
  Fr.attach(13);           // attaching the servos to pins
  Fl.attach(12);
  Br.attach(11);
  Bl.attach(10);           
  pinMode(3, OUTPUT);      // attaching the sprayer to an output pin
  Serial.begin(250000);    // baudrate of Serial monitor
  Dabble.begin(9600);      // baudrate of bluetooth port

void loop() {
  Dabble.processInput();             //this is used to get information from the phone
  Serial.print("KeyPressed: ");
  // is a button is pressed in on the gamepad then the function in the brackets is executed
  if (GamePad.isUpPressed())
  {
    Serial.print("Forward");
    forward();
  }

  if (GamePad.isDownPressed())
  {
    Serial.print("Backward");
    backward();
  }

  if (GamePad.isLeftPressed())
  {
    Serial.print("Left");
    left();
  }

  if (GamePad.isRightPressed())
  {
    Serial.print("Right");
    right();
  }

  if (GamePad.isSquarePressed())
  {
    Serial.print("Square");
  }

  if (GamePad.isCirclePressed())
  {
    Serial.print("Circle");
  }

  if (GamePad.isCrossPressed())
  {
    Serial.print("Cross");
  }

  if (GamePad.isTrianglePressed())
  {
    Serial.print("Triangle");
  }

  if (GamePad.isStartPressed())
  {
    Serial.print("Cleaning");
    clean();
  }

  if (GamePad.isSelectPressed())
  {
    Serial.print("Stopped");
    stop();
  }
  Serial.print('\t');
}
