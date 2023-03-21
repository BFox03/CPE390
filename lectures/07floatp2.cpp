#include <iostream>
#include <iomanip>

using namespace std;

/*
    1/3 = 0.333... 10 is not evenly divisible by 3
    
    001 = 1; 010 = 2; 011 = 3;
    float math  1.1 = 1.5; 1.01 = 1.25; 1.001 = 1.125
    1/10 = (1/5)(1/2) 5 and 2 are coprime

    1/10 = .000110011 (1/16)+(1/32)+(1/256)+(1/512)
*/

int main(){
    cout << setprecision(8);
    for(float i = 0; i <= 10; i+=0.1){
        cout << i << endl;
    }

    float t1 = 70.001;
    float t2 = 70.002;
    float dt = t2 - t1; //0.001~    subtractive cancelilation 

    long double x; //biggest

    /*
        1/1 + 1/2 + 1/3 ... 1/100
        1/100 + 1/99 + 1/98 .. 1/1

        1/1 + 1.0/2
        for(int i = ...)
            1.0/i
        for(float i = ...)
            1/i
        for(float i = ...)
            1.0/i


        1/(1*1) + 1/(2*2) ... = ~1.64
        sqrt(~1.64 *6)
    */

   /*
    a+b = b+a (commutivity) preserved in float
    a+b+c != a+(b+c) (associativity is not preserved)

    1.23
        .0918
        .0599
    ==== 
        3 bits

   1.23
        .09
    ==== 1.32
            0.599
    === 1.37

    doing the small numbers first give 1.38
   */
}