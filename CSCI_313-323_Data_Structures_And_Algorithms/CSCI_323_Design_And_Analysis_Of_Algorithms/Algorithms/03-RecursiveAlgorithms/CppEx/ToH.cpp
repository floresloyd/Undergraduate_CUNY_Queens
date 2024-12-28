#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

///-----------------------------------------------------
/// O(2^n) algorithm to solve Towers of Hanoi problem
///
void ToH(int n, int src, int target, int aux) {
	if (n <= 0) return;

	ToH(n - 1, src, aux, target);
	printf("Move %d from %c to %c\n", n, src, target);
	ToH(n - 1, aux, target, src);
} //end-ToH

int main(){
	ToH(5, 'A', 'C', 'B');

	return 0;
} // end-main

