#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

#define NO_SOL -1  // No solution yet

///============== Naive Recursive Fibonacci =================
int numRecursiveCalls = 0;

int Fibonacci_Recursive(int n) {
	numRecursiveCalls++;

	if (n == 0) return 0;
	if (n == 1) return 1;

	return Fibonacci_Recursive(n - 1) + Fibonacci_Recursive(n - 2);
} // end-Fibonacci_Recursive

///============== Fibonacci with TopDownDP=================
int numRecursiveCallsForFibonacciMemoize = 0;

int Fibonacci_Memoize(int n, vector<int> &T) {
	if (T[n] != NO_SOL) return T[n]; // Already solved? Just return the solution
	
	numRecursiveCallsForFibonacciMemoize++;

	// F(n-1)
	Fibonacci_Memoize(n - 1, T);
	Fibonacci_Memoize(n - 2, T);

	return T[n] = T[n-1] + T[n-2];
} //end-Fibonacci_Memoize

int Fibonacci_TopDownDP(int n) {
	vector<int> T(n+1, NO_SOL); // Solution table. -1 indicates that the problem is NOT solved yet
	// Initialize the solutions for the base cases
	T[0] = 0; 
	T[1] = 1;

	return Fibonacci_Memoize(n, T);
} //end-Fibonacci_TopDownDP

///============== Fibonacci with BottomUpDP 1 =================
int Fibonacci_BottomUpDP(int n) {
	vector<int> T(n+1);

	// Fill-up the solutions for the two base cases
	T[0] = 0;
	T[1] = 1;

	for (int i = 2; i <= n; i++) {
		T[i] = T[i - 1] + T[i - 2];
	} //end-for

	return T[n];
} //end-Fibonacci_BottomUpDP

///============== Fibonacci with BottomUpDP 2 =================
int Fibonacci_BottomUpDP2(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;

	// We just need the solutions to F(n-1), F(n-2).
	// So just store those in two local variables
	int a = 0;  // F(0) => F(n-2)
	int b = 1;  // F(1) => F(n-1)
	int result;

	for (int i = 2; i <= n; i++) {
		result = b + a;  // F(n-1) + F(n-2)
		
		// Change a & b for the next iteration
		a = b;           // a = F(n-1)
		b = result;      // b = F(n)     
	} //end-for

	return result;
} //end-Fibonacci_BottomUpDP2

void FibonacciTest() {
	int n = 25;

	int result = Fibonacci_Recursive(n);
	printf("[Recursive] Fibonacci(%d): %d. Times called: %d\n", n, result, numRecursiveCalls);

	result = Fibonacci_TopDownDP(n);
	printf("[Memoized DP] Fibonacci(%d): %d. Times called: %d\n", n, result, numRecursiveCallsForFibonacciMemoize);

	result = Fibonacci_BottomUpDP(n);
	printf("[BottomUp DP] Fibonacci(%d): %d\n", n, result);

	result = Fibonacci_BottomUpDP2(n);
	printf("[BottomUp DP2] Fibonacci(%d): %d\n", n, result);
} //end-FibonacciTest

int main() {
	FibonacciTest();

	return 0;
} //end-main
