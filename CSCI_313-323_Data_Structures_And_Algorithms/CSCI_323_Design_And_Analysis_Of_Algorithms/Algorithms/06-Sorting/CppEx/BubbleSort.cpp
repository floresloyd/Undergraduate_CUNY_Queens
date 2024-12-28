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
/// O(N^2) Bubble Sort
/// 
void BubbleSort(vector<int>& nums) {
	for (uint32_t iter = 0; iter < nums.size()-1; iter++) {
		/* From start to the end of unsorted part */
		for (uint32_t j = 1; j < (nums.size() - iter); j++) {
			/* If adjacent items out of order, swap */
			if (nums[j - 1] > nums[j]) Swap(nums[j - 1], nums[j]);
		} //end-for-inner
	} //end-for-outer
} //end-BubbleSort

int main(){
	vector<int> nums = { 5, 10, 3, 2, 8, 5, 12, 20, 25, 17, 5, 1, 9, 3, 13, 12, 1 };

	printf("Initial sequence:\n");
	for (auto num: nums) cout << num << ", ";
	cout << "\b\b \n";


	BubbleSort(nums);

	printf("Sorted sequence:\n");
	for (auto num: nums) cout << num << ", ";
	cout << "\b\b \n";

	return 0;
}