#include <stdio.h>
#include <vector>
#include <iostream>
#include <stdint.h>

using namespace std;

///-----------------------------------------------------
/// InsertionSort: O(N^2) worst case, O(N) best case
/// 
void InsertionSort(vector<int>& nums) {
	for (uint32_t P = 1; P < nums.size(); P++) {
		int tmp = nums[P];
		int j = (int)P;
		for (j = P; j > 0 && nums[j - 1] > tmp; j--) {
			nums[j] = nums[j - 1]; //Shift A[j-1] to right
		} //end-for-inner

		nums[j] = tmp; // Found a spot for A[P] (= Tmp)
	} //end-for-outer
} //end-InsertionSort

int main(){
	vector<int> nums = { 5, 10, 3, 2, 8, 5, 12, 20, 25, 17, 5, 1, 9, 3, 13, 12, 1 };

	printf("Initial sequence:\n");
	for (auto num: nums) cout << num << ", ";
	cout << "\b\b \n";

	InsertionSort(nums);

	printf("Sorted sequence:\n");
	for (auto num: nums) cout << num << ", ";
	cout << "\b\b \n";

	return 0;
} // end-main


