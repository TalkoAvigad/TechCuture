#include <Servo.h>
#include <Stepper.h>

const int stepsPerRevolution = 200; 
Stepper myStepper(stepsPerRevolution, 6,7); 
// 6 - INPUT PIN 1
// 7 - INPUT PIN 2
 
//-------------------------
Servo servo_one;  // First Servo Objsect;
Servo servo_two;  // Second Servo Objsect;
Servo servo_three;  // Third Servo Objsect;
Servo servo_four;  // Forth Servo Objsect;


int head_unit_four_pos = 0;    // variable to store the servo position
int head_unit_four_pin = 8;    //BLUE // pin number 11 for the first head unit

int head_unit_one_pos = 0;    // variable to store the servo position
int head_unit_one_pin = 9;    //GREEN // pin number 9 for the first head unit

int head_unit_two_pos = 0;    // variable to store the servo position
int head_unit_two_pin = 10;    //YELLOW // pin number 10 for the second head unit

int head_unit_three_pos = 0;    // variable to store the servo position
int head_unit_three_pin = 11;    //ORANGE // pin number 11 for the first head unit


void setup() {

  // set the speed at 60 rpm:
  myStepper.setSpeed(80);
  // initialize the serial port:
  Serial.begin(9600);
  //------------------------------------
  servo_one.attach(head_unit_one_pin);  // attaches the servo of the head_unit_one
  servo_two.attach(head_unit_two_pin);  // attaches the servo of the head_unit_two
  servo_three.attach(head_unit_three_pin);  // attaches the servo of the head_unit_three
  servo_four.attach(head_unit_four_pin);  // attaches the servo of the head_unit_four
}

void loop() {

  // step one revolution  in one direction:
   Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
  delay(500);

   // step one revolution in the other direction:
  Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution);
  delay(500);
 // ----------------------------------
  headUnitTwo();
  headUnitOne();
//  headUnitThree();
//  headUnitFour();

  testloop();
}

void headUnitOne() {
  for (head_unit_one_pos = 0; head_unit_one_pos <= 180; head_unit_one_pos += 5) {   // goes from 0 degrees to 180 degrees in steps of 1 degree
    servo_one.write(head_unit_one_pos);                                                 // tell servo to go to position in variable 'pos'
    
  }
  delay(1500);                                                                        // waits 15ms for the servo to reach the position
  for (head_unit_one_pos = 180; head_unit_one_pos >= 0; head_unit_one_pos -= 5) {     // goes from 180 degrees to 0 degrees
    servo_one.write(head_unit_one_pos);                                                 // tell servo to go to position in variable 'pos'
    
  }
  delay(1500);                                                                        // waits 15ms for the servo to reach the position
}

void headUnitTwo() {
  for (head_unit_two_pos = 0; head_unit_two_pos <= 180; head_unit_two_pos += 5) {   // goes from 0 degrees to 180 degrees in steps of 1 degree
    servo_two.write(head_unit_two_pos);                                                 // tell servo to go to position in variable 'pos'
  }
  delay(1500);                                                                        // waits 15ms for the servo to reach the position
  
  for (head_unit_two_pos = 180; head_unit_two_pos >= 0; head_unit_two_pos -= 5) {     // goes from 180 degrees to 0 degrees
    servo_two.write(head_unit_two_pos);                                                 // tell servo to go to position in variable 'pos'
  }
  delay(1500);                                                                        // waits 15ms for the servo to reach the position
}

void headUnitThree() {
  for (head_unit_three_pos = 0; head_unit_three_pos <= 180; head_unit_three_pos += 5) {   // goes from 0 degrees to 180 degrees in steps of 1 degree
    servo_three.write(head_unit_three_pin);                                                 // tell servo to go to position in variable 'pos'
    
  }
  delay(1500);                                                                        // waits 15ms for the servo to reach the position
  for (head_unit_three_pos = 180; head_unit_three_pos >= 0; head_unit_three_pos -= 5) {     // goes from 180 degrees to 0 degrees
    servo_three.write(head_unit_three_pos);                                                 // tell servo to go to position in variable 'pos'
    
  }
  delay(1500);                                                                        // waits 15ms for the servo to reach the position
}

void headUnitFour() {
  
  for (head_unit_four_pos = 0; head_unit_four_pos <= 180; head_unit_four_pos += 5) {   // goes from 0 degrees to 180 degrees in steps of 1 degree
    servo_four.write(head_unit_four_pos);                                                 // tell servo to go to position in variable 'pos'
  }
  delay(1500);                                                                        // waits 15ms for the servo to reach the position
  
  for (head_unit_four_pos = 180; head_unit_four_pos >= 0; head_unit_four_pos -= 5) {     // goes from 180 degrees to 0 degrees
    servo_four.write(head_unit_four_pos);                                                 // tell servo to go to position in variable 'pos'
  }
  delay(1500);                                                                        // waits 15ms for the servo to reach the position
  
}

void testloop(){

    for (head_unit_four_pos = 0; head_unit_four_pos <= 180; head_unit_four_pos += 5) {   // goes from 0 degrees to 180 degrees in steps of 1 degree
    servo_four.write(head_unit_four_pos);                                                 // tell servo to go to position in variable 'pos'
  }
  delay(1500);                                                                        // waits 15ms for the servo to reach the position

    for (head_unit_three_pos = 0; head_unit_three_pos <= 180; head_unit_three_pos += 5) {   // goes from 0 degrees to 180 degrees in steps of 1 degree
    servo_three.write(head_unit_three_pos);                                                 // tell servo to go to position in variable 'pos'
  }
  delay(1500);

    for (head_unit_three_pos = 180; head_unit_three_pos >= 0; head_unit_three_pos -= 5) {     // goes from 180 degrees to 0 degrees
    servo_three.write(head_unit_three_pos);                                                 // tell servo to go to position in variable 'pos'
  }
  delay(1500); 


  
  
  for (head_unit_four_pos = 180; head_unit_four_pos >= 0; head_unit_four_pos -= 5) {     // goes from 180 degrees to 0 degrees
    servo_four.write(head_unit_four_pos);                                                 // tell servo to go to position in variable 'pos'
    servo_three.write(head_unit_four_pos);                                                 // tell servo to go to position in variable 'pos'
  }
  delay(5000);  
  
}
