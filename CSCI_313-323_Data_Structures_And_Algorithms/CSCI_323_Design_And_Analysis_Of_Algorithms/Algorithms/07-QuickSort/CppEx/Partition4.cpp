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
/// Predicate-based partitioning
///
template<class UnaryPredicate>
int Partition4(vector<int> &nums, UnaryPredicate predicate) {
	// Find the first cell for which the predicate fails
	int n = nums.size();
	int index = 0;
	for (; index < n && predicate(nums[index]); index++);

	// Go over the rest of the array & swap elements
	// that satisfy the predicate with nums[index]
	for (int i=index+1; i<n; i++){
		if (predicate(nums[i]))
			Swap(nums[index++], nums[i]);
	} // end-for

	return index;
} //end-Partition4

//-------------------------------------------
// Move all numbers < 10 to the beginning of the array
// Preserve the order of the elements in the original array
void Test1(){
	vector<int> nums = {9, 16, 3, 4, 15, 1, 10, 2, 5, 9, 12};
//	vector<int> nums = { 42, 71, 10, 14, 42, 95, 63, 38, 27, 81, 56 };
//	vector<int> nums = {1, 3, 4, 6, 8, 9, 10, 11, 15};
//	vector<int> nums = { 4, 6, 3, 1, 10, 4, 8, 15, 9, 11 };

	printf("nums before calling partition:\n");
	PrintVector(nums);

	int pivot = 10;
	auto predicate = [pivot](int num){return num < pivot;};
	int index = Partition4(nums, predicate);

	printf("Moved all numbers < %d to the beginning.\n", pivot);
	printf("[index: %d]\n", index);
	if (index < nums.size()) printf("nums[index]: %d\n", nums[index]);

	PrintVector(nums);
} // end-Test1

void Test2(){
	vector<int> nums = {9, 16, 3, 4, 15, 1, 10, 2, 5, 9, 12};
//	vector<int> nums = { 42, 71, 10, 14, 42, 95, 63, 38, 27, 81, 56 };
//	vector<int> nums = {1, 3, 4, 6, 8, 9, 10, 11, 15};
//	vector<int> nums = { 4, 6, 3, 1, 10, 4, 8, 15, 9, 11 };

	printf("nums before calling partition:\n");
	PrintVector(nums);

	auto predicate = [](int num){return num % 2 == 1;};
	int index = Partition4(nums, predicate);
	printf("[index: %d]\n", index);
	if (index < nums.size()) printf("nums[index]: %d\n", nums[index]);

	PrintVector(nums);
} // end-Test2

///---------------------------------------------------
/// main
/// 
int main() {
	Test1();
	printf("--------------------------------------------------\n");
	Test2();
} // end-main
