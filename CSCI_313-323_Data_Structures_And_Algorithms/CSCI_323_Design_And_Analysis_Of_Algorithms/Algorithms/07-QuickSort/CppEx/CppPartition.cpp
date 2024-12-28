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

///----------------------------------------------------
/// Cpp partition is predicate-based
/// Partitions the array so that 
/// elements satisfying the predicate goes to the left
/// elements NOT satisfying the predicate goes to the right
/// Returns the index of the first element that does NOT satisfy the predicate
/// There is nothing else we can say about that element 
void Test1(){
	vector<int> nums = { 55, 71, 42, 10, 14, 95, 63, 38, 27, 81, 56 };

	printf("nums before calling partition:\n");
	PrintVector(nums);

	int pivot = 50;
#if 1
	auto iter = std::stable_partition(nums.begin(), nums.end(), 
			[pivot](int num) {
				return num < pivot;
			});
#else
	auto iter = std::partition(nums.begin(), nums.end(), 
			[pivot](int num) {
				return num < pivot;
			});
#endif
	printf("nums after partitioning with predicate num < %d:\n", pivot);
	PrintVector(nums);
	int index = std::distance(nums.begin(), iter);
	printf("[index: %d]\n", index);
	if (index < nums.size()) printf("nums[index]: %d\n", nums[index]);
} // end-Test1

void Test2(){
	vector<int> nums = { 42, 71, 42, 10, 14, 95, 63, 38, 27, 81, 56 };

	printf("nums before calling partition:\n");
	PrintVector(nums);
#if 1
	auto iter = std::stable_partition(nums.begin(), nums.end(), 
			[](int num) {
				return num % 2 == 1;
			});
#else
	auto iter = std::partition(nums.begin(), nums.end(), 
			[](int num) {
				return num % 2 == 1;
			});
#endif

	printf("nums after partitioning:\n");
	PrintVector(nums);
	int index = std::distance(nums.begin(), iter);
	printf("[index: %d]\n", index);
	if (index < nums.size()) printf("nums[index]: %d\n", nums[index]);
} // end-Test2

int main() {
	Test1();
	printf("-----------------------------------------------\n");
	Test2();
} // end-main