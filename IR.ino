#include <Servo.h>
Servo servoLeft;
Servo servoRight;

void setup()                            
{ 
tone(4, 3000, 1000);                  
servoLeft.attach(12);
servoRight.attach(13);                             
// Built-in initialization block 
// Play tone for 1 second 
// Delay to finish tone 
pinMode(10, INPUT);  pinMode(9, OUTPUT);   // Left IR LED & Receiver 
pinMode(3, INPUT);  pinMode(2, OUTPUT);    
// Right IR LED & Receiver 
pinMode(8, OUTPUT); pinMode(7, OUTPUT);    
Serial.begin(9600);                   
// Indicator LEDs 
// Set data rate to 9600 bps 
}   
void loop()                             
{ 
// Main loop auto-repeats 
  delay(100);
  int irLeft = irDetect(9, 10, 38000);  // Check for object on left 
  int irRight = irDetect(2, 3, 38000); 

  if (!irLeft && !irRight)
  {
    digitalWrite(8, 1);             
    digitalWrite(7, 1);
    move_back(1000);
    digitalWrite(8, 0);             
    digitalWrite(7, 0);

  }
  else if(!irLeft)
  {
    digitalWrite(8, 1);             
    move_right(700);
    digitalWrite(8, 0);             
    
  }
  else if(!irRight)
  {
    digitalWrite(7, 1);             
    move_left(700);
    digitalWrite(7, 0);             
   
  }
  else
  {
    move_foreward();             
                           
  } 
}

int irDetect(int irLedPin, int irReceiverPin, long frequency) 
{ 
tone(irLedPin, frequency, 8);         
// IRLED 38 kHz for at least 1 ms 
delay(1);                             
// Wait 1 ms 
int ir = digitalRead(irReceiverPin);  // IR receiver -> ir variable 
delay(1);                             
// Down time before recheck 
return ir;                            
}   


void move_foreward()
{
  
 
  servoLeft.writeMicroseconds(1300);
  servoRight.writeMicroseconds(1700);
  
    
}
void move_back(int time)
{
  servoLeft.writeMicroseconds(1700);
  servoRight.writeMicroseconds(1300);
  delay(time);
 
}
void move_left(int time)
{
 
  servoLeft.writeMicroseconds(1300);
  servoRight.writeMicroseconds(1300); 
  delay(time);
}
void move_right(int time)
{

  servoLeft.writeMicroseconds(1700);
  servoRight.writeMicroseconds(1700); 
  delay(time);
  
}