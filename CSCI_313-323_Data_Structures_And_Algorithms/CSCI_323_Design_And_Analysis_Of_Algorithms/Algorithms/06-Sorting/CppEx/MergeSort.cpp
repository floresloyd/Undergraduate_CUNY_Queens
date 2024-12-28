#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

///-----------------------------------------------------
/// MergeSort: O(NlogN) with O(N) extra space
/// 
void MS(vector<int>& A, int left, int right, vector<int>& B) {
	if (left >= right) return;  // A list of size <= 1 is already sorted

	int middle = left + (right-left) / 2;
	MS(A, left, middle, B);        // Sort the LHS of size N/2
	MS(A, middle + 1, right, B);   // Sort the RHS of size N/2

	// Merge the two halves: O(N)
	int i = left;
	int j = middle + 1;
	int k = 0;
	while (i <= middle && j <= right) {
		if (A[i] <= A[j]) B[k++] = A[i++];
		else              B[k++] = A[j++];
	} //end-while

	// Copy the remaining items from A to B
	while (i <= middle) B[k++] = A[i++];
	while (j <= right) B[k++] = A[j++];

	// Copy the sorted items from B to A
	k = left;
	i = 0;
	while (i < right - left + 1) A[k++] = B[i++];
} //end-MS

void MergeSort(vector<int>& A) {
	if (A.size() <= 1) return;

	vector<int> B(A.size());   // Allocate a temporary buffer of size N
	MS(A, 0, (int)A.size()-1, B);
} //end-MergeSort


int main(){
	vector<int> nums = { 5, 10, 3, 2, 8, 5, 12, 20, 25, 17, 5, 1, 9, 3, 13, 12, 1 };

	printf("Initial sequence:\n");
	for (auto num: nums) cout << num << ", ";
	cout << "\b\b \n";

	MergeSort(nums);

	printf("Sorted sequence:\n");
	for (auto num: nums) cout << num << ", ";
	cout << "\b\b \n";

	return 0;
} // end-main

