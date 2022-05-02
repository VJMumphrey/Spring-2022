#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>
#include <Servo.h> 

Servo Fr;
Servo Fl;
Servo Br;
Servo Bl;

void forward(){Fr.writeMicroseconds(1000); Fl.writeMicroseconds(2000); Br.writeMicroseconds(1000); Bl.writeMicroseconds(2000);}  // function to move the robot forward
void backward(){Fr.writeMicroseconds(2000); Fl.writeMicroseconds(1000); Br.writeMicroseconds(2000); Bl.writeMicroseconds(1000);} // function to move the robot backward
void right(){Fr.writeMicroseconds(1500); Fl.writeMicroseconds(2000); Br.writeMicroseconds(1500); Bl.writeMicroseconds(1000);}    // function to turn the robot right
void left() {Fr.writeMicroseconds(1000); Fl.writeMicroseconds(1500); Br.writeMicroseconds(1000); Bl.writeMicroseconds(1500);}    // function to turn the robot left
void stop(){Fr.writeMicroseconds(1500); Fl.writeMicroseconds(1500); Br.writeMicroseconds(1500); Bl.writeMicroseconds(1500);}     // function to stop the robot
void spray(){digitalWrite(3, HIGH); delay(100);}                                                                                 // function to spray the cleaning solution
void clean(){ spray(); delay(100); forward(); delay(2500); spray(); delay(100); forward(); delay(2500); right(); delay(1000); forward(); delay(1000); right(); delay(1000); spray(); delay(100); forward(); delay(5000);} // function for automatic cleaning

void setup() {
 
  Fr.attach(13); 
  Fl.attach(12);
  Br.attach(11);
  Bl.attach(10);           // attaching the servos to pins
  pinMode(3, OUTPUT);      // attaching the sprayer to an output pin
  Serial.begin(250000);    // make sure your Serial Monitor is also set at this baud rate.
  Dabble.begin(9600);      //Enter baudrate of your bluetooth.Connect bluetooth on Bluetooth port present on evive.
}

void loop() {
  Dabble.processInput();             //this function is used to refresh data obtained from smartphone.Hence calling this function is mandatory in order to get data properly from your mobile.
  Serial.print("KeyPressed: ");
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

  int a = GamePad.getAngle();
  Serial.print("Angle: ");
  Serial.print(a);
  Serial.print('\t');
  int b = GamePad.getRadius();
  Serial.print("Radius: ");
  Serial.print(b);
  Serial.print('\t');
  float c = GamePad.getXaxisData();
  Serial.print("x_axis: ");
  Serial.print(c);
  Serial.print('\t');
  float d = GamePad.getYaxisData();
  Serial.print("y_axis: ");
  Serial.println(d);
  Serial.println();
}
