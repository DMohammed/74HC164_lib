#ifndef SN74HC164D_H
#define SN74HC164D_H
#include <Arduino.h>

class SN74HC164D
{
public:
    void begin(uint8_t a, uint8_t b, uint8_t clk, uint8_t clr);
    //  bitOrder = { LSBFIRST, MSBFIRST };
    void write(uint8_t value ,uint8_t bitOrder = LSBFIRST);
    void rainbow();

private:
    uint8_t _a, _b, _clk, _clr;
};

#endif