#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

///-----------------------------------------------------
/// O(n) algorithm to compute a^n
/// 
double Power1(double a, int n) {
	double partialResult;

	/* Base cases */
	if (n == 0) return 1;
	if (n == 1) return a;

	/* partialResult = a^(n-1) */
	partialResult = Power1(a, n - 1);

	/* Merge */
	return partialResult * a;
} /* end-Power1 */

///-----------------------------------------------------
/// O(logn) algorithm to compute a^n
/// 
double Power2(double a, int n) {
	double partialResult;

	/* Base cases */
	if (n == 0) return 1;
	if (n == 1) return a;

	/* partialResult = a^(n-1) */
	partialResult = Power2(a, n/2);

	/* Merge */
	double result = partialResult * partialResult;
	if (n % 2) result *= a;

	return result;
} /* end-Power2 */

int main(){
	printf("Power1(12, 17): %.0lf\n", Power1(12, 17));
	printf("Power2(12, 17): %.0lf\n", Power2(12, 17));

	return 0;
} // end-main


