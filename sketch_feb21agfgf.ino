void setup()                            
{ 
  tone(4, 3000, 1000);                  
  delay(1000);  

  pinMode(10, INPUT);  pinMode(9, OUTPUT);  

  Serial.begin(9600);                   
}   

void loop()                             
{ 
  int irLeft = irDetect(9, 10, 38000); 

    Serial.println(irLeft);  

  delay(100);                           
} 

int irDetect(int irLedPin, int irReceiverPin, long frequency) 
{ 
  tone(irLedPin, frequency, 8);          
  delay(1);                             
  int ir = digitalRead(irReceiverPin);   
  delay(1);                             
  return ir;                            
}  