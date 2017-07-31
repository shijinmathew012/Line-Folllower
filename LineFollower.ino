#include <AFMotor.h>

int leftFarRead;
int leftNearRead;
int rightNearRead;
int rightFarRead;

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);



int lineValue = 200;   //value may change with sensor
int initialspeed=255;  //Decreses this value to decrese motor speed


void setup()
{ 
  Serial.begin(9600);
  delay(1000);
}

void loop()
{

leftFarRead=analogRead(A0);
leftNearRead=analogRead(A1);
rightNearRead=analogRead(A2);
rightFarRead=analogRead(A3);

//    Serial.print(leftFarRead);
//    Serial.print("\t");  
//    Serial.print(leftNearRead);
//    Serial.print("\t");  
//    Serial.print(rightNearRead);
//    Serial.print("\t"); 
//    Serial.print(rightFarRead);
//    Serial.print("\t");     
//    Serial.println();

  if((rightNearRead < lineValue)&& (rightFarRead < lineValue) &&  (leftFarRead > lineValue) && (leftNearRead < lineValue))
  {
  left();
  }
    else if((rightNearRead < lineValue)&& (rightFarRead < lineValue) &&  (leftFarRead < lineValue) && (leftNearRead >lineValue))
  {
 
  left();
  }
  
  else if((rightNearRead < lineValue)&& (rightFarRead > lineValue) &&  (leftFarRead < lineValue) && (leftNearRead < lineValue))
  {
   right();
  }
   else if((rightNearRead > lineValue)&& (rightFarRead < lineValue) &&  (leftFarRead < lineValue) && (leftNearRead < lineValue))
  {
   right();
  }

 else if((leftFarRead > lineValue) && (leftNearRead > lineValue) && (rightNearRead < lineValue)&& (rightFarRead  <lineValue)  )
  {
    
   left ();
  }
  
  else if((rightNearRead > lineValue)&& (rightFarRead > lineValue)&&  (leftFarRead < lineValue) && (leftNearRead < lineValue) )
  {
    
    right ();
  }
  else if((rightNearRead > lineValue)&& (rightFarRead > lineValue) &&  (leftFarRead > lineValue) && (leftNearRead > lineValue) )
  {
    
    Stop();
  }
  else
  {
  
    forward();
  }
  delay(10);  
}

void right() {
  motor1.setSpeed(0);
  motor2.setSpeed(0);
  motor3.setSpeed(initialspeed);
  motor4.setSpeed(initialspeed);
  motor1.run(FORWARD); 
  motor2.run(FORWARD); 
  motor3.run(FORWARD); 
  motor4.run(FORWARD);
  Serial.println("right");
}
void Stop () {
  motor1.setSpeed(0);
  motor2.setSpeed(0);
  motor3.setSpeed(0);
  motor4.setSpeed(0);
  motor1.run(FORWARD); 
  motor2.run(FORWARD); 
  motor3.run(BACKWARD); 
  motor4.run(BACKWARD);
  Serial.println("stop");
}
void left() {
  motor1.setSpeed(initialspeed);
  motor2.setSpeed(initialspeed);
  motor3.setSpeed(0);
  motor4.setSpeed(0);
  motor1.run(FORWARD); 
  motor2.run(FORWARD); 
  motor3.run(FORWARD); 
  motor4.run(FORWARD);
   Serial.println("left");
}
void forward() {
  motor1.setSpeed(initialspeed);
  motor2.setSpeed(initialspeed);
  motor3.setSpeed(initialspeed);
  motor4.setSpeed(initialspeed);
  motor1.run(FORWARD); 
  motor2.run(FORWARD); 
  motor3.run(FORWARD); 
  motor4.run(FORWARD);
}
void back(){

  motor1.setSpeed(initialspeed);
  motor2.setSpeed(initialspeed);
  motor3.setSpeed(initialspeed);
  motor4.setSpeed(initialspeed);
  motor1.run(BACKWARD); 
  motor2.run(BACKWARD); 
  motor3.run(BACKWARD); 
  motor4.run(BACKWARD);
}


