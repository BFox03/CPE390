#include <iostream>
#include <iomanip>
#include <cmath>

int main(){
    uint8_t a = 255; // 11111111
    uint32_t b = 4'200'000'000U;
    float f = 1.2345678f; // 32 bits
    f = 12.345678f;
    f = 1.2345678e+38f; //Never use float because it is inaccurate
    f = 1.2345678e-38f;          
    /*
        sign = 1 0/1
        exponent = 8 where is the binary place
        mantissa = 24 digits of the number
            1xxxxxxxxxxxxxxxxxxxxxxx
            000101 = 101

        0 01111111 00000000000000000000000
                 1.00000000000000000000000
                 10.00000000000000000000000
    */

    double d = 1.23456789012345;
}