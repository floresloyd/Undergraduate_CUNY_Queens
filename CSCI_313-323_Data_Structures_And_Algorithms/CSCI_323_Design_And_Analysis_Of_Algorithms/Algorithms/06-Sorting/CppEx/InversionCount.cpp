#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

///-----------------------------------------------------
/// InversionCount: O(NlogN) with O(N) extra space
/// 
int IC(vector<int>& A, int left, int right, vector<int>& B) {
	if (left >= right) return 0;  // A list of size <= 1 has no unordered elements

	int middle = left + (right-left) / 2;
	int count = IC(A, left, middle, B);     // Sort the LHS of size N/2 & count the number of inversions
	count += IC(A, middle + 1, right, B);   // Sort the RHS of size N/2 & count the number of inversions

	// Merge the two halves: O(N)
	int i = left;
	int j = middle + 1;
	int k = 0;
	while (i <= middle && j <= right) {
		if (A[i] <= A[j]) B[k++] = A[i++];
		else {
			B[k++] = A[j++]; 
			count += (middle-i+1);   // A[j] skipping over A[i..middle] (middle-i+1) elements
		} // end-else
	} //end-while

	// Copy the remaining items from A to B
	while (i <= middle) B[k++] = A[i++];
	while (j <= right) B[k++] = A[j++];

	// Copy the sorted items from B to A
	k = left;
	i = 0;
	while (i < right - left + 1) A[k++] = B[i++];

	return count;
} //end-IC

int InversionCount(vector<int>& A) {
	if (A.size() <= 1) return 0;

	vector<int> B(A.size());   // Allocate a temporary buffer of size N
	return IC(A, 0, (int)A.size() - 1, B);
} //end-InversionCount

int main(){
	vector<int> A = { 4, 1, 3, 2, 5, 7, 8, 6 };  // InversionCount: 6
	vector<int> B = { 6, 8, 4, 1, 7, 2, 5, 3 };  // InversionCount: 18

	cout << "Inversion count in A: " << InversionCount(A) << endl;
	cout << "Inversion count in B: " << InversionCount(B) << endl;

	return 0;
} // end-main
