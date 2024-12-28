#include <iostream>
using namespace std;

int removeOdd(int n){
    if(n < 10){
        if(n % 2 == 0) return n;
        else return 0;  // for odd numbers that we want to remove
    }

    int evenNum = n % 10;

    if (evenNum % 2 == 0) return evenNum + 10*removeOdd(n / 10);
    else removeOdd(n/10);
}

int removeEven(int n){
    if(n < 10){
        if(n % 2 == 1) return n;    // keep odd numbers
        else return 0;              // chop off even numbers
    };

    int testNum = n % 10;       // returns the last number to test

    if(testNum % 2 == 1) return testNum + 10*(removeEven(n/10));
    else return removeEven(n/10);
}

int main(){
    int test = 123456
    ;
    int n = 5149835;
    cout << "Input: " << test << "\n";
    cout << "removeOdd: " << removeOdd(test) << "\n";
    cout << "removeEvden: "<< removeEven(test) << "\n";


    return 0;
}