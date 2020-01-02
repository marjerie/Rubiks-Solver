#include <AccelStepper.h>
#include <MultiStepper.h>

#define dirPin1 3
#define stepPin1 2
#define dirPin2 4
#define stepPin2 5
#define dirPin3 6
#define stepPin3 7
#define dirPin4 8
#define stepPin4 9
#define dirPin5 10
#define stepPin5 11
#define dirPin6 12
#define stepPin6 13
#define stepsPerRevolution 3200
#define ETX 0x03

AccelStepper stepper1(AccelStepper::DRIVER, stepPin1, dirPin1);
AccelStepper stepper2(AccelStepper::DRIVER, stepPin2, dirPin2);
AccelStepper stepper3(AccelStepper::DRIVER, stepPin3, dirPin3);
AccelStepper stepper4(AccelStepper::DRIVER, stepPin4, dirPin4);

MultiStepper steppers13;

char cmd[128];
int delay_value = 1000;
int roll_delay = 500;
int rotate_delay = 2000;
int M1[] = {dirPin1,stepPin1};
int M2[] = {dirPin2,stepPin2};
int M3[] = {dirPin3,stepPin3};
int M4[] = {dirPin4,stepPin4};
int M5[] = {dirPin5,stepPin5};
int M6[] = {dirPin6,stepPin6};

void setup() {
  // Declare pins as output:
  Serial.begin(9600);
  pinMode(stepPin1, OUTPUT);
  pinMode(dirPin1, OUTPUT);
  pinMode(stepPin2, OUTPUT);
  pinMode(dirPin2, OUTPUT);
  pinMode(stepPin3, OUTPUT);
  pinMode(dirPin3, OUTPUT);
  pinMode(stepPin4, OUTPUT);
  pinMode(dirPin4, OUTPUT);
  pinMode(stepPin5, OUTPUT);
  pinMode(dirPin5, OUTPUT);
  pinMode(stepPin6, OUTPUT);
  pinMode(dirPin6, OUTPUT);
  stepper1.setMaxSpeed(100);
  stepper2.setMaxSpeed(100);
  stepper3.setMaxSpeed(100);
  stepper4.setMaxSpeed(100);
  stepper1.setAcceleration(100);
  stepper2.setAcceleration(100);
  stepper3.setAcceleration(100);
  stepper4.setAcceleration(100);
  steppers13.addStepper(stepper1);
  steppers13.addStepper(stepper3);
}


void loop() {
if (Serial.available()) { 
  int a = Serial.parseInt();
  if (a==1) { 
   // D();
  // rollbackM6();
  //rollfrontM6();
  
 rotate180(M1[0],M1[1]);
//delay(2000);
//rotate180(M2[0],M2[1]);
//delay(2000);
//rotate180(M3[0],M3[1]);
//delay(2000);
//rotate180(M4[0],M4[1]);
//delay(2000);
//L();
//delay(2000);
//Fdash();
//delay(2000);
//B2();

//Ldash();
//delay(2000);
//Udash();
//delay(2000);
//Rdash();
//delay(2000);

}
}
  }
void rollbackM5()
{
  digitalWrite(dirPin5, LOW);
  for (int i = 0; i < stepsPerRevolution/1.5; i++) {
    digitalWrite(stepPin5, HIGH);
    delayMicroseconds(roll_delay);
    digitalWrite(stepPin5, LOW);
    delayMicroseconds(roll_delay);
  }
  delay(delay_value);
}

void rollfrontM5()
{
  digitalWrite(dirPin5, HIGH);
  for (int i = 0; i < stepsPerRevolution/1.5; i++) {
    digitalWrite(stepPin5, HIGH);
    delayMicroseconds(roll_delay);
    digitalWrite(stepPin5, LOW);
    delayMicroseconds(roll_delay);
  }
  delay(delay_value);
}
void rollfrontM5dummy()
{
  digitalWrite(dirPin5, HIGH);
  for (int i = 0; i < stepsPerRevolution/4; i++) {
    digitalWrite(stepPin5, HIGH);
    delayMicroseconds(roll_delay);
    digitalWrite(stepPin5, LOW);
    delayMicroseconds(roll_delay);
  }
  delay(delay_value);
}

void rollbackM6()
{
  digitalWrite(dirPin6, HIGH);
  for (int i = 0; i < stepsPerRevolution/1.5; i++) {
    digitalWrite(stepPin6, HIGH);
    delayMicroseconds(roll_delay);
    digitalWrite(stepPin6, LOW);
    delayMicroseconds(roll_delay);
  }
  delay(delay_value);
}

void rollfrontM6()
{
  digitalWrite(dirPin6, LOW);
  for (int i = 0; i < stepsPerRevolution/1.5; i++) {
    digitalWrite(stepPin6, HIGH);
    delayMicroseconds(roll_delay);
    digitalWrite(stepPin6, LOW);
    delayMicroseconds(roll_delay);
  }
  delay(delay_value);
}

void rollfrontM6dummy()
{
  digitalWrite(dirPin6, LOW);
  for (int i = 0; i < stepsPerRevolution/4; i++) {
    digitalWrite(stepPin6, HIGH);
    delayMicroseconds(roll_delay);
    digitalWrite(stepPin6, LOW);
    delayMicroseconds(roll_delay);
  }
  delay(delay_value);
}

void rotate90(int dirPin,int stepPin)
{
  digitalWrite(dirPin, LOW);
  for (int i = 0; i < stepsPerRevolution/28; i++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(rotate_delay);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(rotate_delay);
  }
  digitalWrite(dirPin, HIGH);
  for (int i = 0; i < stepsPerRevolution/28 - stepsPerRevolution/32; i++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(rotate_delay);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(rotate_delay);
  }
  delay(delay_value);
}

void rotate180(int dirPin,int stepPin)
{
  digitalWrite(dirPin, LOW);
  for (int i = 0; i < stepsPerRevolution/15; i++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(rotate_delay);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(rotate_delay);
  }
    digitalWrite(dirPin, HIGH);
  for (int i = 0; i < stepsPerRevolution/15 - stepsPerRevolution/16; i++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(rotate_delay);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(rotate_delay);
  }
  delay(delay_value);
}

void rotatecounter90(int dirPin,int stepPin)
{
  digitalWrite(dirPin, HIGH);
  for (int i = 0; i < stepsPerRevolution/28.5; i++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(rotate_delay);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(rotate_delay);
  }
  digitalWrite(dirPin, LOW);
  for (int i = 0; i < stepsPerRevolution/28.5 - stepsPerRevolution/31; i++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(rotate_delay);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(rotate_delay);
  }
delay(delay_value);
}

void rotatecounter180(int dirPin,int stepPin)
{
  digitalWrite(dirPin, HIGH);
  for (int i = 0; i < stepsPerRevolution/15; i++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(rotate_delay);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(rotate_delay);
  }
  digitalWrite(dirPin, LOW);
  for (int i = 0; i < stepsPerRevolution/15 - stepsPerRevolution/16; i++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(rotate_delay);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(rotate_delay);
  }
  delay(delay_value);
}

void R()
{
  rotatecounter90(M1[0],M1[1]);
  rollbackM5();
  rotate90(M1[0],M1[1]);
  rollfrontM5();
}

void L()
{
  rotatecounter90(M3[0],M3[1]);
  rollbackM5();
  rotate90(M3[0],M3[1]);
  rollfrontM5();
}

void f()
{
  rotatecounter90(M2[0],M2[1]);
  rollbackM6();
  rotate90(M2[0],M2[1]);
  rollfrontM6();
}

void B()
{
  rotatecounter90(M4[0],M4[1]);
  rollbackM6();
  rotate90(M4[0],M4[1]);
  rollfrontM6();
}

void Rdash()
{
  rotate90(M1[0],M1[1]);
  rollbackM5();
  rotatecounter90(M1[0],M1[1]);
  rollfrontM5();
}

void Ldash()
{
  rotate90(M3[0],M3[1]);
  rollbackM5();
  rotatecounter90(M3[0],M3[1]);
  rollfrontM5();
}

void Fdash()
{
  rotate90(M2[0],M2[1]);
  rollbackM6();
  rotatecounter90(M2[0],M2[1]);
  rollfrontM6();
}

void Bdash()
{
  rotate90(M4[0],M4[1]);
  rollbackM6();
  rotatecounter90(M4[0],M4[1]);
  rollfrontM6();
}

void R2()
{
  rotate180(M1[0],M1[1]);
}

void L2()
{
  rotate180(M3[0],M3[1]);
}

void F2()
{
  rotate180(M2[0],M2[1]);
}

void B2()
{
  rotate180(M4[0],M4[1]);
}

void rollupD()
{
  long positions[2];
  positions[0] = 100;
  positions[1] = -100;
  steppers13.moveTo(positions);
  steppers13.runSpeedToPosition(); 
  delay(roll_delay);
}

void rolldownD()
{
  long positions[2];
  positions[0] = 0;
  positions[1] = 0;
  steppers13.moveTo(positions);
  steppers13.runSpeedToPosition(); 
  delay(roll_delay);
}

void rollupU()
{
  long positions[2];
  positions[0] = -100;
  positions[1] = 100;
  steppers13.moveTo(positions);
  steppers13.runSpeedToPosition(); 
  delay(roll_delay);
}

void rolldownU()
{
  long positions[2];
  positions[0] = 0;
  positions[1] = 0;
  steppers13.moveTo(positions);
  steppers13.runSpeedToPosition(); 
  delay(roll_delay);
}

void D()
{
  rollbackM6();
  rollfrontM5dummy();
  rollupD();
  rollfrontM6();
  rollbackM5();
  rolldownD();
  rollfrontM5();
  f();
  rollbackM6();
  rollfrontM5dummy();
  rollupD();
  rollfrontM6();
  rollbackM5();
  rolldownD();
  rollfrontM5();
}

void U()
{
  rollbackM6();
  rollfrontM5dummy();
  rollupU();
  rollfrontM6();
  rollbackM5();
  rolldownU();
  rollfrontM5();
  f();
  rollbackM6();
  rollfrontM5dummy();
  rollupU();
  rollfrontM6();
  rollbackM5();
  rolldownU();
  rollfrontM5();
}

void Ddash()
{
  rollbackM6();
  rollfrontM5dummy();
  rollupD();
  rollfrontM6();
  rollbackM5();
  rolldownD();
  rollfrontM5();
  Fdash();
  rollbackM6();
  rollfrontM5dummy();
  rollupD();
  rollfrontM6();
  rollbackM5();
  rolldownD();
  rollfrontM5();
}

void Udash()
{
  rollbackM6();
  rollfrontM5dummy();
  rollupU();
  rollfrontM6();
  rollbackM5();
  rolldownU();
  rollfrontM5();
  Fdash();
  rollbackM6();
  rollfrontM5dummy();
  rollupU();
  rollfrontM6();
  rollbackM5();
  rolldownU();
  rollfrontM5();
}

void D2()
{
  rollbackM6();
  rollfrontM5dummy();
  rollupD();
  rollfrontM6();
  rollbackM5();
  rolldownD();
  rollfrontM5();
  F2();
  rollbackM6();
  rollfrontM5dummy();
  rollupD();
  rollfrontM6();
  rollbackM5();
  rolldownD();
  rollfrontM5();
}

void U2()
{
  rollbackM6();
  rollfrontM5dummy();
  rollupU();
  rollfrontM6();
  rollbackM5();
  rolldownU();
  rollfrontM5();
  F2();
  rollbackM6();
  rollfrontM5dummy();
  rollupU();
  rollfrontM6();
  rollbackM5();
  rolldownU();
  rollfrontM5();
}

