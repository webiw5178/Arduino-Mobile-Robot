#include <Servo.h>
Servo servoLeft;
Servo servoRight;

void setup() 
{
  servoLeft.attach(13);

  servoRight.attach(12);
  move_back(3000);
  move_right(950);
  move_back(3000);
  move_right(950);
  move_back(3000);
  move_right(950);
  move_back(3000);
  move_right(950);
  servoLeft.detach();
  servoRight.detach();


}

void loop() {
  
  
  

}

void move_foreward(int time)
{
  
  tone(4, 3000, 1000);
  Serial.println("Moving Forward");
  servoLeft.writeMicroseconds(1300);
  servoRight.writeMicroseconds(1700);
  delay(time);
    
}
void move_back(int time)
{
  tone(4, 3000, 1000);
  Serial.println("Moving Back");
  servoLeft.writeMicroseconds(1700);
  servoRight.writeMicroseconds(1300);
  delay(time);
 
}
void move_left(int time)
{
  tone(4, 3000, 1000);
  Serial.println("Moving Left");
  servoLeft.writeMicroseconds(1300);
  servoRight.writeMicroseconds(1300);  
  delay(time);
}
void move_right(int time)
{
  tone(4, 3000, 1000);
  Serial.println("Moving Right");
  servoLeft.writeMicroseconds(1700);
  servoRight.writeMicroseconds(1700); 
  delay(time); 
}
void pause(int time)
{
  servoLeft.writeMicroseconds(1500);
  servoRight.writeMicroseconds(1500); 
  delay(time); 
}