#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

///-------------------------------------------------
/// Prints the elements of the array on the screen
///
static void PrintVector(vector<int>& nums) {
	printf("nums=[");

	for (auto num : nums)
		printf("%d, ", num);

	printf("\b\b]\n");
} //end-PrintVector

///--------------------------------------------------------
/// Partition using extra space
///
int Partition1(vector<int> &nums) {
	int n = nums.size();
	vector<int> arr(n);  // Temporary buffer

	int k = 0;
	int pivot = nums[0];

	// Predicate: num < pivot
	auto predicate = [pivot](int num){return num < pivot;};

	// Can also make the Predicate: num <= pivot
//	auto predicate = [pivot](int num){return num <= pivot;};

	for (int i = 1; i < n; i++) {
		if (predicate(nums[i])) arr[k++] = nums[i];
	} //end-for

	// Put the pivot in its proper place
	int index = k;    // This is the index where we will put the pivot in
	arr[k++] = pivot;

	// Copy all elements >= pivot
	for (int i = 1; i < n; i++) {
		if (!predicate(nums[i])) arr[k++] = nums[i];
	} //end-for

	// Copy all elements from B to A
	for (int i = 0; i < n; i++) nums[i] = arr[i];

	return index;
} //end-Partition1

///---------------------------------------------------
/// main
/// 
int main() {
	vector<int> nums = {9, 16, 3, 4, 15, 1, 10, 2, 5, 9, 12};
//	vector<int> nums = { 42, 71, 10, 14, 42, 95, 63, 38, 27, 81, 56 };
//	vector<int> nums = {1, 3, 4, 6, 8, 9, 10, 11, 15};
//	vector<int> nums = { 4, 6, 3, 1, 10, 4, 8, 15, 9, 11 };

	printf("nums before calling partition:\n");
	PrintVector(nums);

	int index = Partition1(nums);
	printf("[index: %d], [pivot: %d]\n", index, nums[index]);

	PrintVector(nums);
} // end-main
