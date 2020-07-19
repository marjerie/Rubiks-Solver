# Rubiks-Solver
To solve a Rubik's cube with the help of stepper motors using Arduino

# Components
* NEMA 17 stepper motor (4)
* NEMA 23 stepper motor (2)
* TB6600 Drivers
* Arduino Uno

# Working
Stepper motors are used to control the rotation of grippers which rotate the faces of the cube during the cube solving process. 
The Bot utilizes an Arduino UNO microcontroller to control and coordinate the rotation of the stepper motors.
The four grippers, used to rotate the faces of the cube, are manipulated using four NEMA 17 stepper motors which are mounted on a platform. 
These platforms are placed on aluminium rails and are connected to two NEMA 23 stepper motors which aid in its back and forth movement. 
A NEMA 23 stepper motor, which is positioned below the rails, helps with the motion of two NEMA 17 stepper motors.

# Pin Connections
<b>NEMA 17 stepper motor</b>

Motor 1:<br>
dirPin1 3
stepPin1 2

Motor 2:<br>
dirPin2 4
stepPin2 5

Motor 3:<br>
dirPin3 6
stepPin3 7

Motor 4:<br>
dirPin4 8
stepPin4 9

<b>NEMA 23 stepper motor</b>

Motor 1:<br>
dirPin5 10
stepPin5 11

Motor 2:<br>
dirPin6 12
stepPin6 13

# General functions available
* rotate90(dirPin, stepPin) - gripper rotates 90 degrees in clockwise direction
* rotate180(dirPin, stepPin) - gripper rotates 180 degrees in clockwise direction
* rotatecounter90(dirPin, stepPin) - gripper rotates 90 degrees in counter clockwise direction
* rotatecounter180(dirPin, stepPin) - gripper rotates 180 degrees in counter clockwise direction

# Functions to implement "Singmaster notation" on Rubik's Cube
* L() - to rotate left face 90 degrees in clockwise direction
* R() - to rotate right face 90 degrees in clockwise direction
* F() - to rotate front face 90 degrees in clockwise direction
* B() - to rotate back face 90 degrees in clockwise direction
* U() - to rotate upper face 90 degrees in clockwise direction
* D() - to rotate lower face 90 degrees in clockwise direction
* Ldash() - to rotate left face 90 degrees in counter clockwise direction
* Rdash() - to rotate right face 90 degrees in counter clockwise direction 
* Fdash() - to rotate front face 90 degrees in counter clockwise direction
* Bdash() - to rotate back face 90 degrees in counter clockwise direction
* Udash() - to rotate upper face 90 degrees in counter clockwise direction 
* Ddash() - to rotate lower face 90 degrees in counter clockwise direction
* L2() - to rotate left face 180 degrees in clockwise direction
* R2() - to rotate right face 180 degrees in clockwise direction
* F2() - to rotate front face 180 degrees in clockwise direction
* B2() - to rotate back face 180 degrees in clockwise direction
* U2() - to rotate upper face 180 degrees in clockwise direction
* D2() - to rotate lower face 180 degrees in clockwise direction
