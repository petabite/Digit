#ifndef Digit_h
#define Digit_h

#include "Arduino.h"

class Digit
{
    public:
        Digit(byte a_pin, byte b_pin, byte c_pin, byte d_pin, byte e_pin, byte f_pin, byte g_pin, byte dp_pin);
        void Digit::displayMessage(String str, int delay_ms);
        void display(int num, boolean decimal = false);
        void display(char c, boolean period = false);
        void clear();
    private:
        void set(byte segs[], byte size);
        const byte segments[8];
        byte a_pin, b_pin, c_pin, d_pin, e_pin, f_pin, g_pin, dp_pin;
};

#endif
