#include <stdio.h>
#include <vector>
#include <iostream>
#include <stdint.h>

using namespace std;

///-----------------------------------------------------
/// Swap two values using the xor operator w/o a temporary variable
/// 
void Swap(int& a, int& b) { 
	if (&a == &b) return;
	a = a ^ b; 
	b = a ^ b; 
	a = a ^ b; 
} // end-Swap

///-----------------------------------------------------
/// O(N^2) Selection Sort
///  
void SelectionSort(vector<int>& nums) {
	for (uint32_t i = 0; i < nums.size()-1; i++) {
		int minIndex = i;   // min index
		for (uint32_t j = i + 1; j < nums.size(); j++) {
			if (nums[j] < nums[minIndex]) minIndex = j;
		} //end-for-inner

		if (i != minIndex) Swap(nums[i], nums[minIndex]);
	} //end-for-outer
} //end-SelectionSort

int main(){
	vector<int> nums = { 5, 10, 3, 2, 8, 5, 12, 20, 25, 17, 5, 1, 9, 3, 13, 12, 1 };

	printf("Initial sequence:\n");
	for (auto num: nums) cout << num << ", ";
	cout << "\b\b \n";


	SelectionSort(nums);

	printf("Sorted sequence:\n");
	for (auto num: nums) cout << num << ", ";
	cout << "\b\b \n";

	return 0;
} // end-main


