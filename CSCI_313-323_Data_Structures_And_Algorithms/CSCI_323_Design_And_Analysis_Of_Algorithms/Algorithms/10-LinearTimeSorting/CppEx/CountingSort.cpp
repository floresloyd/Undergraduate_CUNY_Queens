#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

void CountingSort1(vector<int>& A);

struct Item {
	int key;
	char val;

	Item() { key = 0; val = 0; }
	Item(int _key, char _val) { key = _key; val = _val; }
};

void CountingSort2(vector<Item>& A);

///---------------------------------------------------------
/// Test CountingSort Algorithms
///
void Print(vector<int>& A) {
	printf("A=[");
	for (size_t i = 0; i < A.size(); i++) {
		printf("%d", A[i]);
		if (i < A.size() - 1) printf(", ");
		else                printf("]\n");
	} // end-for
} //end-Print

void Print(vector<Item>& A) {
	printf("A=[");
	for (size_t i = 0; i < A.size(); i++) {
		printf("<%d, %c>", A[i].key, A[i].val);
		if (i < A.size() - 1) printf(", ");
		else                  printf("]\n");
	} // end-for
} //end-Print

///---------------------------------------------------------
/// Counting Sort 1: Just the values
///
void CountingSort1(vector<int>& A) {
	if (A.size() <= 1) return;

	/// Find the minimum and maximum values
	int min = A[0];
	int max = A[0];

	for (size_t i = 1; i < A.size(); i++) {
		if (A[i] < min) min = A[i];
		else if (A[i] > max) max = A[i];
	} //end-for

	// Now, allocate the C array
	int N = max - min + 1;
	int* C = new int[N];

	// Set all slots in C to 0
	for (int i = 0; i < N; i++) C[i] = 0;

	// Count the number of occurrences of each number
	for (size_t i = 0; i < A.size(); i++) {
		C[A[i] - min]++;
	} //end-for

	// Now, walk over the count array and fill up A
	int k = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < C[i]; j++) {
			A[k++] = i + min;
		} //end-for
	} //end-for

	delete[] C;
} //end-CountingSort1

///---------------------------------------------------------
/// Counting Sort 2: When the key is associated with some satellite value
///                  i.e., we have <key, value> pairs
///
void CountingSort2(vector<Item>& A) {
	if (A.size() <= 1) return;

	/// Find the minimum and maximum values
	int min = A[0].key;
	int max = A[0].key;

	for (size_t i = 1; i < A.size(); i++) {
		if (A[i].key < min) min = A[i].key;
		else if (A[i].key > max) max = A[i].key;
	} //end-for

	// Now, allocate the C array
	int N = max - min + 1;
	int* C = new int[N];

	// Set all slots in C to 0
	for (int i = 0; i < N; i++) C[i] = 0;

	// Count the number of occurrences of each number
	for (size_t i = 0; i < A.size(); i++) {
		C[A[i].key - min]++;
	} //end-for

	// Add up the values in C to compute the index of each number
	for (int i = 1; i < N; i++) C[i] += C[i - 1];

	// Allocate a temporary B array to copy the result into
	Item* B = new Item[A.size()];

	// Now, walk in the reverse direction over A and copy the items to B in sorted order
	for (int i = (int)A.size() - 1; i >= 0; i--) {
		int index = C[A[i].key - min] - 1;
		B[index] = A[i];

		C[A[i].key - min]--;
	} // end-for

	// Finally, copy the sorted items from B to A
	for (int i = 0; i < A.size(); i++) {
		A[i] = B[i];
	} //end-for

	delete[] C;
	delete[] B;
} //end-CountingSort2

///--------------------------------------------------------------------------
/// Test code
/// 
void Test1() {
	vector<int> A = { 3, 5, 4, 3, 7, 4, 5, 6, 3, 8, 7, 6, 4 };
	//	vector<int> A = { 3, 5, 4, 3, -1, -5, -2, 7, 4, -1, 5, -2, -2, -1, 6, 3, 8, 7, 6, 4 };

	printf("Before sort: ");
	Print(A);

	// Sort the array using Counting Sort
	CountingSort1(A);

	// Print the sorted array
	printf("After sort:  ");
	Print(A);
} // end-Test1

void Test2(){
	vector<Item> A = { Item(1, 'a'), Item(4, 'e'), Item(3, 'r'), Item(1, 's'), Item(3, 'v') };
	//	vector<Item> A = { Item(1, 'a'), Item(4, 'e'), Item(1, 'k'), Item(3, 'r'), Item(4, 'm'), Item(1, 's'), Item(3, 'v') };

	printf("Before sort: ");
	Print(A);

	// Sort the array using Counting Sort
	CountingSort2(A);

	// Print the sorted array
	printf("After sort:  ");
	Print(A);
} //end-Test2

int main(){
//	Test1();
	Test2();
} // end-main

