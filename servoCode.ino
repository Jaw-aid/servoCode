#include <Servo.h>

Servo myServo1;
Servo myServo2;

int switchState = 0;
int servo2Offset = 10;

void setup()
{
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    myServo1.attach(9);
    myServo2.attach(10);

    // Set the initial positions with the offset
    myServo1.write(0);
    myServo2.write(0 + servo2Offset);
}

void loop()
{
    switchState = digitalRead(2);
    if (switchState == HIGH)
    {
        Serial.print("Button was pressed \n");
        myServo1.write(179);
        myServo2.write(179);
        delay(1000);
        myServo1.write(0);
        myServo2.write(0 + servo2Offset);
    }
}
