#include <Servo.h>
void setup() // Built-in initialization block
{
 tone(4, 3000, 1000); 
 delay(1000);
 pinMode(10, INPUT); pinMode(9, OUTPUT);
 pinMode(3, INPUT); pinMode(2, OUTPUT); 
 Serial.begin(9600); 
}

void loop() 
{
 int irLeft = irDistance(9, 10); 
 int irRight = irDistance(2, 3); 
 Serial.print(irLeft); 
 Serial.print(" "); 
 Serial.println(irRight);
 delay(100); 
}

int irDistance(int irLedPin, int irReceivePin)
{
 int distance = 0;
 for(long f = 38000; f <= 42000; f += 1000) {
 distance += irDetect(irLedPin, irReceivePin, f);
 }
 return distance;
}

int irDetect(int irLedPin, int irReceiverPin, long frequency)
{
 tone(irLedPin, frequency, 8); 
 delay(1); 
int ir = digitalRead(irReceiverPin); 
 delay(1); 
 return ir; 
} 