//  1. Write a recursive function removeOddDigits that takes a positive integer and returns a new integer with
//  all odd digits of the input removed.
//  int removeOddDigits(int n);
//  Ex: sumDigit(5149835) 48
//     biggestDigit(35)  0 

#include <iostream>
using namespace std;

int sumDigit(int n){
    if (n < 10) return n;
    return sumDigit(n / 10) + n % 10;
}

int main(){
    int test = 123;
    int n = 5149835;
    cout << sumDigit(test);
}