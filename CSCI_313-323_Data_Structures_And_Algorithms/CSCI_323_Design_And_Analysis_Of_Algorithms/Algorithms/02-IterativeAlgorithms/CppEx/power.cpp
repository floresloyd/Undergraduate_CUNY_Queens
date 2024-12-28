#include <stdio.h>
#include <vector>
#include <iostream>
#include <cstdint>

using namespace std;

/// --------------------------------------------------
/// Compute a^n in O(N) time
///
int Power1(int a, int n) {
    uint32_t pow = 1;
    while (n > 0) {
        pow *= a;
        n--;
    } // end-while

    return pow;
} //end-Power1

/// --------------------------------------------------
/// Compute a^n in O(logN) time
///
int Power2(int a, int n) {
    int pow = 1;
    int currentPow = a;

    while (n > 0) {
        if (n & 0x1) pow *= currentPow;
        currentPow *= currentPow;
        n >>= 1; // n = n/2
    } // end-while

    return pow;
} //end-Power2

int main() {
    printf("3^10: %d, 3^10: %d\n", Power1(3, 10), Power2(3, 10));
    printf("5^18: %d, 5^18: %d\n", Power1(5, 18), Power2(5, 18));

    return 0;
} // end-main
