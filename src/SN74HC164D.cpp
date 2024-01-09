#include <Arduino.h>
#include "SN74HC164D.h"

void SN74HC164D::begin(uint8_t a, uint8_t b, uint8_t clk, uint8_t clr)
{
    pinMode(a, OUTPUT);
    pinMode(b, OUTPUT);
    pinMode(clk, OUTPUT);
    pinMode(clr, OUTPUT);
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(clk, HIGH);
    digitalWrite(clr, LOW);
    delay(50);
    digitalWrite(clr, HIGH);
    _a = a;
    _b = b;
    _clk = clk;
    _clr = clr;
}

void SN74HC164D::write(uint8_t value, uint8_t bitOrder)
{
    digitalWrite(_b, HIGH);
    digitalWrite(_clr, LOW);
    delay(5);
    digitalWrite(_clr, HIGH);
    for (byte i = 0; i < 8; i++)
    {
        digitalWrite(_clk, LOW);
        if (bitOrder)
            digitalWrite(_a, bitRead(value, 7 - i));
        else
            digitalWrite(_a, bitRead(value, i));
        delay(1);
        digitalWrite(_clk, HIGH);
        delay(1);
    }
    digitalWrite(_b, LOW);
}

void SN74HC164D::rainbow()
{
    digitalWrite(_b, HIGH);
    for (byte i = 0; i < 8; i++)
    {
        digitalWrite(_a, HIGH);
        digitalWrite(_clk, LOW);
        delay(100);
        digitalWrite(_clk, HIGH);
        delay(100);
        digitalWrite(_clk, LOW);
        delay(100);
        digitalWrite(_clk, HIGH);
        delay(100);
        digitalWrite(_a, LOW);
        digitalWrite(_clk, LOW);
        delay(100);
        digitalWrite(_clk, HIGH);
        delay(100);
        digitalWrite(_clk, LOW);
        delay(100);
        digitalWrite(_clk, HIGH);
        delay(100);
    }
    digitalWrite(_b, LOW);
}