#include <iostream>
using namespace std;

int main(){
    uint32_t a = 0x2B | ~0x2B; // 0x0000002B | 0xFFFFFFD4 = 0xFFFFFFFF
    uint64_t b = 0x2B | ~0x2B; // 0x000000000000002B | 0x0000000FFFFFFD4 = 0x0000000FFFFFFFF
    uint64_t c = 0x2BULL | ~ 0x2BULL; // 0xFFFFFFFFFFFFFFFF
    uint64_t d = 0x2b & ~ 0x2b; //0x0000000000000000
}