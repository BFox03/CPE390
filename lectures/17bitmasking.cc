/*
    bit twiddling
    bit masking
    10101011001001010100100010011010xxx100100

    1. make a set of bits = 0
    2. make a set of bits = 1
    3. toggle a set of bits
    4. test whether all bits marked x are 1
    5. test whether any bits marked x are 1
*/


#include <iostream>
using namespace std;

uint32_t clear(uint32_t a, uint32_t mask){
    return a & mask; //whichever bits in mask are 0 are removed
}

uint32_t set(uint32_t a, uint32_t mask){
    return a | mask; //whichever bits in mask are 1 are removed
}

uint32_t toggle(uint32_t a, uint32_t mask){
    return a ^ mask;
}


// 10000010101111100
//          xxxx
// if not all 1 then a&mask will not be 0
bool allMaskedBitsSet(uint32_t a, uint32_t mask){
    return (a & mask) == mask; // whichever bits in mask are 1 tested
}

int main(){
    uint32_t a = 0x1234ABFD; // 0001 0010 0011 0100 1010 1011 1111 1101
                             //                     xxxx
                             // 1111 1111 1111 1111 0001 1111 1111 1111
                             //=0001 0010 0011 0100 0000 1011 1111 1101 = 12340BFD
    cout << hex << clear(a, 0xFFFF1FFF) << endl;


                            // 0001 0010 0011 0100 1010 1011 1111 1101
                            //                xx         xx
                            // 0000 0000 0000 1100 0000 0110 0000 0000
    cout << hex << set(a, 0x000C0600) << endl;

                            // 0001 0010 0011 0100 1010 1011 1111 1101
                            //                x               xxx xxxx
                            // 0000 0000 0000 1000 0000 0000 0111 1111
    cout << hex << toggle(a, 0x0008007F);        

}