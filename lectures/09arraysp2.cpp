#include <iostream>

using namespace std;

int g(int x){
    return x*x;
}

int f(int x){
    //uint32_t a[1024*1024]; //16 bil bits 4 mil bytes
    int y = g(x);
    return y*4;
}

int main(){
    int y = f(3);

    cout << y;
}