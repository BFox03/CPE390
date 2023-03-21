#include <iostream>

using namespace std;

/*
    Author: Brandon Fox
    
    Sources: CPE 390 Lab 1 Assignment
*/

double product(const int a[], int n) {
    double product = 1;
    for(int i = 0; i < n; i++){
        product = product * a[i];
    }
    return product;
}

int main() {
  int a[] = {5, 3, 1, 9};
  double z = product(a, 4);// 135 is the answer
  cout << z << '\n';
}
