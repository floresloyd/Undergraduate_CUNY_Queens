#include <iostream>
using namespace std;

int bigint(int n){
    if (n < 10) return n;
    
    int bigD = n % 10; // Returns Last digit and we store this
    return std::max(bigD, bigint(n / 10));
}

int main(){
    int n = 5149435;
    int n2 = 4624253614;
    cout << bigint(n2);
}