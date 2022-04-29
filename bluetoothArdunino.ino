#include <Servo.h>

// assign the servo names respective to their position on the ardunio
Servo  ServoFl;
Servo  ServoFr;
Servo  ServoBl;
Servo  ServoBr;

void setup() {
	Serial.begin(9600);
	pinMode(13, OUTPUT);
	ServoFl.attach(9);
	ServoFr.attach(10);
	ServoBl.attach(11);
	ServoBr.attach(12);
}

void loop () {
	if (Serial.available() > 0) {
		int command = Serial.parseInt();
		if (command == 1) {
			// cleanBoard();	
		}
		if (command == 2) {
			// up				
		}
		if (command == 3) {
			// down
		}
		if (command == 4) {
			// left
		}
		if (command == 5) {
			// Right
		}
	}
}
/*
clean the board with a automatic cycle
*/
void cleanBoard() {
			
}

void foward() {
	ServoFl.writeMicroseconds(2000);
	ServoFr.writeMicroseconds(1000);
	ServoBl.writeMicroseconds(1000);
	ServoBr.writeMicroseconds(2000);
}

void backward() {
	ServoFl.writeMicroseconds(1000);
	ServoFr.writeMicroseconds(2000);
	ServoBl.writeMicroseconds(2000);
	ServoBr.writeMicroseconds(1000);
}

void left() {
	
}

void right() {

}
