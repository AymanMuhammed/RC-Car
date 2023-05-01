# RC-Car


### 1. introduction

Welcome to our RC car project! In this project, we aim to design and build a remote-controlled car that can be controlled using a smartphone app. The car will be equipped with various sensors and actuators, allowing it to perform a range of maneuvers and tasks.

Our project is open-source, meaning that anyone can contribute to the development of the car. We encourage you to get involved and help us make the car even better!

<p align="center">
  <img src="https://gcdnb.pbrd.co/images/GuSgB2UidUMr.jpg?o=1">
</p>

### 2.  Work Phases

 - We wrote a demo code to check that everything is working, to 
make sure of the polarity of each motor and make sure that the 
components work, then we implemented the car with all the 
wiring connections.
 - We wrote the full code of the Bluetooth module and the path 
detection, we kept testing it on the car and do all the problem 
solving until it worked properly.

 - We wrote the line-track code but The IR sensor wasn't able to 
detect the line instantaneously

 - We tried to stop the car and take readings and moving according 
to these readings but it was too slow and it harms the motors and 
body.
- We made the code of IR using interrupts to take the action 
instantaneously
 <p align="center">
  <img src="https://gcdnb.pbrd.co/images/DQs2sKC266el.jpg?o=1">
</p>

### 3.  The Obstacles

- First, we had a problem working with the driver module L293D 
as it was so hard connecting the sensors on the pins, so we 
replaced it with the driver module L298N.
- Second, we had a problem with the car high speed and a 
problem with turning left or right, so we modified the code by 
decreasing the speed and modifying the direction of motors 
while turning left or right.
- Third, we did a short circuit by mistake on the battery holder
so we replaced it


### 4.  How the car works in the Application
1) first thing we can connect program 
with the car by Bluetooth module
(2) we choose the mood that we want 
the car to work on it. Push the triangle 
to be on : makes the car follow line with IR Sensors. Push the triangle 
to be off: makes the car moves in the main directions Backward, 
Forward, Right , Left and the sub directions Forward-Right, ForwardLeft, Back-Right and Back- Left by using the arrows shown at the 
screen.
 <p align="center">
  <img src="https://gcdnb.pbrd.co/images/FqAKVM4gmyQQ.jpg?o=1">
</p>

### 5.  How to Run the Car
- The motors drives a high current which the Arduino can't supply 
so we bought a driver to get the required current 
- it contain H-Bridge to change the direction which the current 
move into motor to change the motor direcrion 
- The car contain 4 wheels Each 2 wheels connected parallel and 
connected to driver output. 
- To move forward we move all the motors forward.
- To move backward we move all the motors backward.
- To move right we move the left motors forward and stop the 
right motors.
- To move left we move the right motors forward and stop the left 
motors.


 
