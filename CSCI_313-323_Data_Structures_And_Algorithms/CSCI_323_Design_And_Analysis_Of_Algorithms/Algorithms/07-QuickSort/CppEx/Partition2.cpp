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
/// Swaps two integers
///
void inline Swap(int& a, int& b) {
	// If a & b are the same memory slot, nothing to swap. Just return
	// Without this check, xor based code will NOT work, 
	// because when a & b are the same memory slot, the xor will make the value 0!
	if (&a == &b) return;
#if 0
	// Swap using extra memory
	int tmp = a;
	a = b;
	b = tmp;
#else	
	// Swap using xor
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
#endif
} //end-Swap

///--------------------------------------------------------
/// Partition w/o extra space
///
int Partition2(vector<int> &nums) {
	int n = nums.size();
	if (n <= 1) return 0;

	int pivot = nums[0];  // Pivot is the first element
	int i = 1, j = n - 1;

	while (true) {
		while (nums[i] < pivot && i < j) i++;  // Move i
		while (nums[j] > pivot) j--;           // Move j

		// Are we done?					
		if (i >= j) break;

		// Swap nums[i] and nums[j]
		Swap(nums[i], nums[j]);

		i++; j--;
	} //end-while

	// Restore the pivot
	nums[0] = nums[j];
	nums[j] = pivot;

	return j;  // return the index of the pivot
} //end-Partition2

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

	int index = Partition2(nums);
	printf("[index: %d], [pivot: %d]\n", index, nums[index]);

	PrintVector(nums);
} // end-main
