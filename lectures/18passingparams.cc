#include <iostream>
#include <iomanip>
#include <bitset>
#include <cmath>
using namespace std;


// %ecx     %edx intel        %esi    %edi linux
int f(int a, int b){
    
}

// %rcx     %rdx intel 
uint64_t g(uint64_t a, uint64_t b){

}

//              %xmm0     %xmm1     %rcx        %rdx  
void rect2polar(double x, double y, double& r, double& theta){
    r = sqrt(x*x+y*y);
    theta = atan2(y,x);

}

int main(){
    int u = f(2,3);
    uint64_t z = g(5,6);
    double x = 3;
    double y = 4;
    double r , theta;
}