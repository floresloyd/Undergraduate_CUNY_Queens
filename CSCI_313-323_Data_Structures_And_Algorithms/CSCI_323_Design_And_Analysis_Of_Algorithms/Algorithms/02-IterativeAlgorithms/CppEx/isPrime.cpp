#include <stdio.h>
#include <vector>
#include <iostream>
#include <cstdint>

using namespace std;

/// --------------------------------------------------
/// O(n) algorithm for primality check
///
bool isPrime1(int n) {
    if (n == 1) return false;
    if (n == 2) return true;

    int x = 2;
    while (x < n) {
        if (n % x == 0) return false;
        x++;
    } // end-while

    return true;
} //end-isPrime1

/// --------------------------------------------------
/// O(sqrt(n)) algorithm for primality check
///
bool isPrime2(int n) {
    if (n == 1) return false;
    if (n == 2) return true;

    int x = 2;
    while (x*x <= n) {
        if (n % x == 0) return false;
        x++;
    } // end-while

    return true;
} //end-isPrime2

int main() {
    cout << "isPrime1(5)? " << isPrime1(5) << ", " << "isPrime2(5)? " << isPrime2(5) << endl;
    cout << "isPrime1(10002035)? " << isPrime1(10002035) << ", " << "isPrime2(10002035)? " << isPrime2(10002035) << endl;
    cout << "isPrime1(1299709)? " << isPrime1(1299709) << ", " << "isPrime2(1299709)? " << isPrime2(1299709) << endl;

	return 0;
} // end-main


