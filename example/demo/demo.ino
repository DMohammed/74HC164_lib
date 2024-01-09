#include <Arduino.h>
#include <SN74HC164D.h>

SN74HC164D xx164;

void setup()
{
    Serial.begin(9600);
    Serial.println("test");
    xx164.begin(7, 6, 5, 4);
    xx164.rainbow();
}

void loop()
{
    if (Serial.available())
        xx164.write(Serial.read() - 48, MSBFIRST);
}
