#include <Servo.h>

Servo servo_one;  // First Servo Objsect;
Servo servo_two;  // Second Servo Objsect;

int head_unit_one_pos = 0;    // variable to store the servo position
int head_unit_one_pin = 8;    // pin number 8 for the first head unit
int head_unit_two_pos = 0;    // variable to store the servo position
int head_unit_two_pin = 10;   // pin number 10 for the second head unit
char NumberOfLevel = 0;

const int dirPin = 2;         
const int stepPin = 3;
const int stepsToMove = 1000;
int delayMicro=600;            //250-600 Normal speed per quarter step

int headUnitOnePosDown = 0;
int headUnitOnePosUp = 180;

int headUnitTwoPosDown = 0;
int headUnitTwoPosUp = 180;


void setup() {
  Serial.begin(9600);
  servo_one.attach(head_unit_one_pin);  // attaches the servo of the head_unit_one pin 8
  servo_two.attach(head_unit_two_pin);  // attaches the servo of the head_unit_two pin 10
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
}

void loop(){
  NumberOfLevel = 0;
  
  if (Serial.available() > 0) {
    NumberOfLevel = Serial.read();
  }
  
  switch (NumberOfLevel){
    case '0':
      Serial.println("Run for all step");
      LoweringNeedleDown();
      delay(1000); // Wait a second
      ServoMotorWrapped();
      delay(1000); // Wait a second
      NeedleRotation();
      delay(1000); // Wait a second
      LiftingNeedleUp();
      delay(1000); // Wait a second
      NeedleRotationBack();
      delay(1000); // Wait a second
      ServoMotorWrappedBack();
      delay(1000); // Wait a second
      break;
    case '1':
      Serial.println("Step 1: Lower the needle");
      LoweringNeedleDown();
      Serial.println("Step 1 done");
      break;
      
    case '2':
      Serial.println("Step 2: Servo motor wrapped in thread on the needle");
      ServoMotorWrapped();
      Serial.println("Step 2 done");        
      break;
      
    case '3':
      Serial.println("Step 3: Rotate the needle counterclockwise 180 degrees");
      NeedleRotation();
      Serial.println("Step 3 done");
      break;
      
    case '4':
      Serial.println("Step 4: Lifting needle up back");
      LiftingNeedleUp();
      Serial.println("Step 4 done");
      break;
      
    case '5':
      Serial.println("Step 5: Rotate the needle clockwise 180 degrees back");
      NeedleRotationBack();
      Serial.println("Step 5 done");
      break;
      
    case '6':
      Serial.println("Step 6: Servo motor wrapped in thread on the needle back");
      ServoMotorWrappedBack();
      Serial.println("Step 6 done");
      break;
  }
}


void LoweringNeedleDown(){
  for (head_unit_one_pos = 180; head_unit_one_pos >= headUnitOnePosDown; head_unit_one_pos -= 5){     // goes from 180 degrees to 0 degrees
    servo_one.write(head_unit_one_pos);                                                               // tell servo to go to position in variable 'pos'
  }
}

void ServoMotorWrapped(){
  // Set motor direction counterclockwise
  digitalWrite(dirPin, LOW);
 
  // Spin motor quickly
  for(int x = 0; x < stepsToMove; x++)
  {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(delayMicro);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(delayMicro);
  }
  delay(1000); // Wait a second
}

void NeedleRotation(){
  for (head_unit_two_pos = 180; head_unit_two_pos >= headUnitTwoPosDown; head_unit_two_pos -= 5) {   // goes from 0 degrees to 180 degrees in steps of 1 degree
    servo_two.write(head_unit_two_pos);                                                              // tell servo to go to position in variable 'pos'
  }
}

void LiftingNeedleUp(){
  for (head_unit_one_pos = 0; head_unit_one_pos <= headUnitOnePosUp; head_unit_one_pos += 5){    // goes from 0 degrees to 180 degrees in steps of 1 degree
    servo_one.write(head_unit_one_pos);                                                          // tell servo to go to position in variable 'pos'
  }
}

void NeedleRotationBack(){
  for (head_unit_two_pos = 0; head_unit_two_pos <= headUnitTwoPosUp; head_unit_two_pos += 5) {   // goes from 0 degrees to 180 degrees in steps of 1 degree
    servo_two.write(head_unit_two_pos);                                                          // tell servo to go to position in variable 'pos'
  }
}

void ServoMotorWrappedBack(){
  digitalWrite(dirPin, HIGH);
   
  // Spin motor quickly
  for(int x = 0; x < stepsToMove; x++){
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(delayMicro);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(delayMicro);
  }
  delay(1000); // Wait a second
}
