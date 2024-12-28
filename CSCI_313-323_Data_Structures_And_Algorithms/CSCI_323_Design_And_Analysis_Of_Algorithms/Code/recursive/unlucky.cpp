#include <iostream>
using namespace std;

bool unlucky(int n){
    if (n < 10) return false;
    if (n < 100){
        if((n/10) + (n % 10) == 13) return true;
    }
    else return unlucky(n/10);
}

int main(){
    int n = 491567;
    cout << unlucky(n);
}