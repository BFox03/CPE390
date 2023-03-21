#include <iostream>

using namespace std;

int main() {
    //count from 1 to 50 odd numbers only 
    for(int i = 1; i <= 50; i+=2){
        cout << i << " ";
    }
    cout << endl;
    
    //count down from 10 to blast off
    for(int i = 10; i >= 0; i--){
        cout << i << " ";
    }
    cout << "Blast off" << endl;

    //by powers of 2 to 1024
    for(int i = 1; i <= 1024; i= i+i){
        cout << i << " ";
    }
}