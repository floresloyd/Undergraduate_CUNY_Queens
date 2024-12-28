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
/// Computes the median of nums[0], nums[N/2] and nums[N-1].
/// Assumes that we have at least 3 items
///
int MedianOf3(vector<int> &nums){
	// Compute the median of nums[0], nums[N/2], nums[N-1]
	int left = 0;
	int right = nums.size() - 1;
	int center = left + (right-left) / 2;

	// Sort nums[left], nums[right], nums[center]
	if (nums[left] > nums[center]) Swap(nums[left], nums[center]);
	if (nums[left] > nums[right]) Swap(nums[left], nums[right]);
	if (nums[center] > nums[right]) Swap(nums[center], nums[right]);

	Swap(nums[center], nums[right - 1]);  // Hide the pivot

	return nums[right - 1];  // Return the pivot
} //end-MedianOf3

///------------------------------------------------------
/// Performs partition using the median of 3 heuristic
/// Assumes N>=3.
///
int Partition3(vector<int> &nums){
	// Compute the pivot using the median of 3 heuristic
	int n = nums.size();
	if (n < 3) return 0;  // We must have 3 elements

	int pivot = MedianOf3(nums);

	int i = 0; int j = n - 2;
	while (true) {
		while (nums[++i] < pivot);
		while (nums[--j] > pivot);

		// Are we done?					
		if (i >= j) break;

		// Swap nums[i] and nums[j]
		Swap(nums[i], nums[j]);
	} //end-while

	Swap(nums[i], nums[n - 2]);  // Restore the pivot

	return i;
} //end-Partition3

///---------------------------------------------------
/// main
/// 
int main() {
//	vector<int> nums = {9, 16, 3, 4, 15, 1, 10, 2, 5, 9, 12};
	vector<int> nums = { 42, 71, 10, 14, 42, 95, 63, 38, 27, 81, 56 };
//	vector<int> nums = {1, 3, 4, 6, 8, 9, 10, 11, 15};
//	vector<int> nums = { 4, 6, 3, 1, 10, 4, 8, 15, 9, 11 };

	printf("nums before calling partition:\n");
	PrintVector(nums);

	int index = Partition3(nums);
	printf("[index: %d], [pivot: %d]\n", index, nums[index]);

	PrintVector(nums);
} // end-main
