#include <Servo.h> // Include servo library

Servo servoLeft; // Declare left and right servos
Servo servoRight;

void setup() // Built-in initialization block
{
    pinMode(10, INPUT);
    pinMode(9, OUTPUT); // Left IR LED & Receiver
    pinMode(3, INPUT);
    pinMode(2, OUTPUT); // Right IR LED & Receiver
    pinMode(8, OUTPUT); pinMode(7, OUTPUT);
    tone(4, 3000, 1000); // Play tone for 1 second
    delay(1000); // Delay to finish tone
    servoLeft.attach(13); // Attach left signal to pin 13
    servoRight.attach(12); // Attach right signal to pin 12
}

void loop() // Main loop auto-repeats
{   delay(150);
    int irLeft = irDetect(9, 10, 38000); // Check for object on left
    int irRight = irDetect(2, 3, 38000); // Check for object on right

    digitalWrite(8, !irLeft); // LED states opposite of IR
    digitalWrite(7, !irRight);

    Serial.print("Left: "); Serial.print(irLeft);
    Serial.print(" | Right: "); Serial.println(irRight);
    
    if ((irLeft == 0) && (irRight == 0)) // If both sides detect
    {
        Serial.println("Obstacle detected on both sides - Backing up and turning");
        maneuver(-150, -150, 900); // Backward for 400 milliseconds
        maneuver(150, -150, 300); // Turn right 500 milliseconds
    }
    else if (irLeft == 0) // If only left side detects
    {
        Serial.println("Obstacle on left side - Adjusting course to the right");
        maneuver(-150, -150, 900);
        maneuver(180, -130, 300); // Adjust right
    }
    else if (irRight == 0) // If only right side detects
    {
        Serial.println("Obstacle on right side - Adjusting course to the left");
        maneuver(-150, -150, 900);
        maneuver(-130, 180, 300); // Adjust left
    }
    else // Otherwise, no IR detects (move forward)
    {
        Serial.println("Path clear - Moving straight");
        maneuver(170, 170, 50); // Forward 50 ms with balanced speed
    }
}

int irDetect(int irLedPin, int irReceiverPin, long frequency)
{
    tone(irLedPin, frequency, 8); // IR LED 38 kHz for at least 1 ms
    delay(1); // Wait 1 ms
    int ir = digitalRead(irReceiverPin); // IR receiver -> ir variable
    delay(1); // Down time before recheck
    return ir; // Return 1 no detect, 0 detect
}

void maneuver(int speedLeft, int speedRight, int msTime)
{
    // Speed tuning for straighter path following
    servoLeft.writeMicroseconds(1500 + speedLeft); // Left servo speed
    servoRight.writeMicroseconds(1500 - speedRight); // Right servo speed

    if (msTime == -1)
    {
        servoLeft.detach(); // Stop servo signals
        servoRight.detach();
    }

    delay(msTime); // Delay for msTime
}