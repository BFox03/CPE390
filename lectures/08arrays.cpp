#include <iostream>

using namespace std;

int main(){
    int a; // 32 bits on machine 4 bytes
    uint64_t b; // 64 bits 8 bytes
    float c; // 32 bits 4 bytes
    double d; // 64 bits 8 bytes

    int e[10]; //single block of 10 int
    double f[100];

    uint32_t  x[3][4]; //3*4*4 = 48 bits
    uint32_t  y[100][5]; //2000 bits will kill the arduino

    cout << &a;
    cout << endl << &b;
    cout << endl << &c;
    cout << endl << &d;
    cout << endl << &e[0];
    cout << endl << &f[0];
}