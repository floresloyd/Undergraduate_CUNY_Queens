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

int CppSelect(int k){
	vector<int> nums = { 42, 71, 42, 10, 14, 95, 63, 38, 27, 81, 56 };

	std::nth_element(nums.begin(), nums.begin()+k, nums.end());
	return nums[k];
} // end-CppSelect

int main() {
	vector<int> nums = { 42, 71, 42, 10, 14, 95, 63, 38, 27, 81, 56 };
	PrintVector(nums);

	for (int k = 0; k < nums.size(); k++) {
		printf("%dth smallest element is: %d\n", k, CppSelect(k));
	} //end-for

	printf("\n\n");
} // end-main
