#include <SoftwareSerial.h>
#define RX 12
#define TX 13
SoftwareSerial BM (RX,TX);
#define rightSensor 2
#define leftSensor 3
#define centerSensor 4
#define speedLeft 5
#define speedRight 6 
#define leftForward 7
#define leftBackward 8
#define rightForward 9
#define rightBackward 10
#define LEDs 14
#define BUZZER 15
int oldState = 0;
int flag = 0;
char command;
void forward(int Speed)
{
  digitalWrite(leftForward,HIGH);
  digitalWrite(rightForward,HIGH);
  digitalWrite(leftBackward,LOW);
  digitalWrite(rightBackward,LOW);
  analogWrite (speedRight,Speed);
  analogWrite (speedLeft,Speed);
} 

void backward(int Speed)
{
  digitalWrite(leftForward,LOW);
  digitalWrite(rightForward,LOW);
  digitalWrite(leftBackward,HIGH);
  digitalWrite(rightBackward,HIGH);
  analogWrite (speedRight,Speed);
  analogWrite (speedLeft,Speed);
} 
void right(int Speed)
{
  digitalWrite(leftForward,HIGH);
  digitalWrite(rightForward,LOW);
  digitalWrite(leftBackward,LOW);
  digitalWrite(rightBackward,HIGH);
  analogWrite (speedRight,80);
  analogWrite (speedLeft,Speed);
  oldState = 2;
} 

void left(int Speed)
{
  digitalWrite(leftForward,LOW);
  digitalWrite(rightForward,HIGH);
  digitalWrite(leftBackward,HIGH);
  digitalWrite(rightBackward,LOW);
  analogWrite (speedRight,Speed);
  analogWrite (speedLeft,80); 
  oldState = 1;
}
void backLeft(int Speed)
{
  digitalWrite(leftForward,LOW);
  digitalWrite(rightForward,LOW);
  digitalWrite(leftBackward,LOW);
  digitalWrite(rightBackward,HIGH);
  analogWrite (speedRight,Speed);
  analogWrite (speedLeft,0);
}
void backRight(int Speed)
{
  digitalWrite(leftForward,LOW);
  digitalWrite(rightForward,LOW);
  digitalWrite(leftBackward,HIGH);
  digitalWrite(rightBackward,LOW);
  analogWrite (speedRight,0);
  analogWrite (speedLeft,Speed);
}

void Stop()
{
  digitalWrite(leftForward,LOW);
  digitalWrite(rightForward,LOW);
  digitalWrite(leftBackward,LOW);
  digitalWrite(rightBackward,LOW);
  analogWrite (speedRight,0);
  analogWrite (speedLeft,0); 
} 
void carLeft()
{ 
    oldState = 2;
    Stop(); delay(30);
      while (digitalRead(rightSensor))
        {
          right(205);   
        }
}
void carRight()
{ 
    oldState = 1;
    Stop(); delay(30); 
    {
      while (digitalRead(leftSensor))
        {
          left(205);   
        }
    }
}


void setup() 
{ 
  BM.begin(9600);
  pinMode(leftForward,OUTPUT);  
  pinMode(leftBackward,OUTPUT); 
  pinMode(rightForward,OUTPUT); 
  pinMode(rightBackward,OUTPUT);
  pinMode(speedLeft,OUTPUT);
  pinMode(speedRight,OUTPUT);
  pinMode(LEDs,OUTPUT);
  pinMode(BUZZER,OUTPUT);
  attachInterrupt(0,carLeft,RISING);
  attachInterrupt(1,carRight,RISING);
  Stop();  
}

void loop()
{
  detachInterrupt(0);
  detachInterrupt(1);
  static int SPEED = 0;
     if(BM.available() > 0)
  { 
    command = BM.read(); 
    switch(command){
    case 'F':  
      forward(SPEED);
      break;
    case 'B':  
       backward(SPEED);
      break;
    case 'L':  
      left(SPEED);
      break;
    case 'R':
      right(SPEED);
      break;
    case 'S':
      Stop();
      break;
    case 'G':  
      left(SPEED);
      break;
    case 'I':
      right(SPEED);
      break;
    case 'J':
      backRight(SPEED);
      break;
    case 'H':
      backLeft(SPEED);
      break; 
    case '0':
      SPEED = 0;
      break;
    case '1':
      SPEED = 70;
      break;
    case '2':
      SPEED = 70;
      break;
    case '3':
      SPEED = 70;
      break;
    case '4':
      SPEED = 120;
      break;
    case '5':
      SPEED = 120;
      break;
    case '6':
      SPEED = 170;
      break;
    case '7':
      SPEED = 170;
      break;
    case '8':
      SPEED = 250;
      break;    
    case '9':
      SPEED = 250;
      break;    
    case 'q':
      SPEED = 250;
      break;
    case 'X':
      attachInterrupt(0,carLeft,RISING);
      attachInterrupt(1,carRight,RISING);
  
      forward(90);
      while (1)
       {               
        forward(80);
        if (!digitalRead(centerSensor)&&!digitalRead(leftSensor)&&!digitalRead(rightSensor)) 
          {
            if (oldState == 1)
            {
              right(200);
              delay(10);
             }
            else if (oldState == 2)
            {
                left(200);
                delay(10);
            }
          if (BM.read()=='x')
                 break; 
         }     
       }
     case'V':
          digitalWrite(LEDs,HIGH);
          break;
      case'v':
        digitalWrite(LEDs,LOW);
        break;
      case'W':
          digitalWrite(BUZZER,HIGH);
          break;
      case'w':
        digitalWrite(BUZZER,LOW);
        break;
     }
  }   
}
