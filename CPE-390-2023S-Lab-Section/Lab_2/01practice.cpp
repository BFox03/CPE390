#include <iostream>
#include <iomanip>
#include <cmath>
#include <bitset>
using namespace std;

/*
    Author: Brandon Fox

    Source: Justin Ferber
            CPE390 Lab 2 

    "I pledge my honor that I have abided by the Stevens Honor System." 
    - Brandon Fox
*/



// int
int gcd(int a, int b){
    int y = a;
    if(a < b){
        y = b;
    }
    int solve = 0;
    for(int i = 1; i <= y; i++){
       if(a%i == 0 && b%i == 0){
        solve = i;
       }
    }
    return solve;
}

bool isPrime(int a){
    if(a==1 || a==0){
            return false;
        }
    for(int i = 2; i< a; i++){
        if (a%i == 0){
            return false;
        }
    }
    return true;
}
int countPrimes(int a, int b){
    int counter = 0;
    for(int i = a; i <= b; i++){
        if (isPrime(i)){
            counter++;
        }
    }
    return counter;
}
// float
float sum_forward(int n){
    float holder = 0;
    for(float i = 1; i <= n; i++){
        holder = (1/i) + holder;
    }
    return holder;
}
float sum_backward(int n){
    float holder = 0;
    for(float i = n; i>= 1; i--){
        holder = (1/i) + holder;
    }
    return holder;
}
double hypot(double a, double b){
    return sqrt(pow(a, 2) + pow(b,2));
}
// array
void double_each(int a[], int n){
    for(int i = 0; i<n; i++){
        a[i] = a[i] * 2;
    }
}
float mean(float x[], int n){
    float mean = 0;
    for(int i = 0; i < n; i++){
        mean = x[i] + mean;
    }
    return mean/n;
}
int prod(int x[], int n){
    int product = 1;
    for(int i = 0; i < n; i++){
        product = x[i] * product;
    }
    return product;
}


int main() {
    //------------------------integer part
    cout << "part 1 output:" << endl;
    cout << "gcd(12, 18)=" << gcd(12, 18) << endl;
    cout << "gcd(1025, 3025)=" << gcd(1025, 3025) << endl;
    cout << "isPrime(5)=" << isPrime(5) << endl;
    cout << "isPrime(9)=" << isPrime(9) << endl;
    cout << "isPrime(1001)=" << isPrime(1001) << endl;
    cout << "isPrime(2601)=" << isPrime(2601) << endl;
    cout << "isPrime(1013)=" << isPrime(1013) << endl;
    cout << "countPrimes(1,100): " << countPrimes(1, 100) << endl;
    cout << "countPrimes(1,10000): " << countPrimes(1, 10000) << endl;
    
    //------------------------floating point number part
    cout << "part 2 output:" << endl;
    float ans_1 = sum_forward(100);
    float ans_2 = sum_backward(100);
    cout << setprecision(8)<< ans_1 << endl;
    cout << setprecision(8) << ans_2 << endl;
    cout << "hypot(3,4)=" << hypot(3, 4) << endl; // should print 5
    cout << "hypot(4,5)=" << hypot(4, 5) << endl;
    //------------------------array part 
    cout << "part 3 output:" << endl;
    float x[] = {10, 20, 30, 40, 50, 60};
    int n = sizeof(x)/sizeof(float);
    cout << mean(x, n) << endl; // should print 35
    float y[] = {1.0, 2.0, 3.0, 4.0};
    cout << mean(y, sizeof(y)/sizeof(float)) << endl; // should print 2.5
    int z[] = {10, 20, 30, 40, 50, 60};
    int z_len = sizeof(z)/sizeof(int);
    double_each(z, z_len);
    for (int i = 0; i < z_len; i++) {
        cout << z[i] << ",";
    }
    cout << endl;
    int a[] = {3, 4, 1, 2, -2};
    cout << prod(a, sizeof(a)/sizeof(int)) << endl;
    int b[] = {2, 4, 8, -2, -4};
    cout << prod(b, sizeof(b)/sizeof(int)) << endl;
    
    return 0;
}
