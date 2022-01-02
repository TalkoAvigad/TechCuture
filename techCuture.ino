#include <Servo.h>

Servo servo_one;  // First Servo Objsect;
Servo servo_two;  // Second Servo Objsect;
bool CheckInput = true;
int head_unit_one_pos = 0;    // variable to store the servo position
int head_unit_one_pin = 8;    // pin number 8 for the first head unit
int head_unit_two_pos = 0;    // variable to store the servo position
int head_unit_two_pin = 10;   // pin number 10 for the second head unit
char NumberOfLevel = 0;

const int dirPin = 2;         
const int stepPin = 3;
const int stepsToMove = 1000;
int delayMicro=600;            //250-600 Normal speed per quarter step


void setup() {
  Serial.begin(9600);
  servo_one.attach(head_unit_one_pin);  // attaches the servo of the head_unit_one
  servo_two.attach(head_unit_two_pin);  // attaches the servo of the head_unit_two
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
}

void loop(){
  NumberOfLevel = 0;
  CheckInput = true;
  
  if (Serial.available() > 0) {
//    if (NumberOfLevel == 0){
//    Menu(NumberOfLevel);
//    }
//    Serial.println("Please select the step:");
    NumberOfLevel = Serial.read();
//    CheckInputStep(NumberOfLevel);
//    Serial.println(NumberOfLevel);
  }
  
  switch (NumberOfLevel){
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
      NeedleRotation();
      Serial.println("Step 5 done");
      break;
      
    case '6':
      Serial.println("Step 6:  ");

      Serial.println("Step 6 done");
      break;
  }
}

int Menu(int i_NumberOfLevel){
  Serial.println("Welcome to TechCouture.");
  delay(1500);
  Serial.flush();
  Serial.println("Step 1: Lower the needle");
  Serial.println("Step 2: Servo motor wrapped in thread on the needle");
  Serial.println("Step 3: Rotate the needle counterclockwise 180 degrees");
  Serial.println("Step 4: Lifting needle up back");
  Serial.println("Step 5: Rotate the needle clockwise 180 degrees back");
  Serial.println("Step 6: ");
}

bool CheckInputStep(int i_GetStepNumber){
  if  (i_GetStepNumber >= 1 && i_GetStepNumber <= 6){
    bool CheckInput = false;
  }
  else{
    Serial.println("Worng Input!");
  }
}

void LoweringNeedleDown(){
  for (head_unit_one_pos = 0; head_unit_one_pos <= 180; head_unit_one_pos += 5){    // goes from 0 degrees to 180 degrees in steps of 1 degree
    servo_one.write(head_unit_one_pos);                                             // tell servo to go to position in variable 'pos'
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

void NeedleRotation(){
  for (head_unit_two_pos = 180; head_unit_two_pos >= 0; head_unit_two_pos -= 5){     // goes from 180 degrees to 0 degrees
    servo_two.write(head_unit_two_pos);                                              // tell servo to go to position in variable 'pos'
  }
}

void LiftingNeedleUp(){
  for (head_unit_one_pos = 180; head_unit_one_pos >= 0; head_unit_one_pos -= 5){     // goes from 180 degrees to 0 degrees
    servo_one.write(head_unit_one_pos);                                              // tell servo to go to position in variable 'pos'
  }
  
}

void NeedleRotationBack(){
  for (head_unit_two_pos = 0; head_unit_two_pos <= 180; head_unit_two_pos += 5) {   // goes from 0 degrees to 180 degrees in steps of 1 degree
  servo_two.write(head_unit_two_pos);                                                 // tell servo to go to position in variable 'pos'
  }
}
