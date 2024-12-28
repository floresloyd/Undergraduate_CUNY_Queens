#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

///-----------------------------------------------------
/// O(N) forward/backward linear search
/// 
int ForwardLinearSearch(vector<int>& A, int key, int index) {
	if (index >= (int)A.size()) return -1;
	
	// Compare with A[index]
	if (key == A[index]) return index;

	// Search in A[index+1..A.size()-1]
	return ForwardLinearSearch(A, key, index + 1);
} //end-ForwardLinearSearch

int BackwardLinearSearch(vector<int>& A, int key, int index) {
	if (index < 0) return -1;

	// Compare with A[index]
	if (key == A[index]) return index;

	// Search in A[0..index-1]
	return BackwardLinearSearch(A, key, index -1);
} //end-ForwardLinearSearch

int LinearSearch(vector<int>& A, int key) {
	return ForwardLinearSearch(A, key, 0);
//	return BackwardLinearSearch(A, key, A.size()-1);
} //end-LinearSearch

int main(){
	vector<int> A = { 9, 4, 10, 1, 20, 12, 3, 99, 65, 52, 25, 11, 91, 24, 20, 33, 22 };
	printf("Index of 20: %d\n", LinearSearch(A, 20));
	printf("Index of 57: %d\n", LinearSearch(A, 57));

	return 0;
} // end-main


