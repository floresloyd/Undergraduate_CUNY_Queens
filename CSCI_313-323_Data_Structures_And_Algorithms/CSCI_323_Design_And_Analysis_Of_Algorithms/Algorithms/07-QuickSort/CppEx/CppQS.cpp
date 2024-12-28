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

///---------------------------------------------------
/// This code is taken from https://en.cppreference.com/w/cpp/algorithm/partition
///
template<class ForwardIt>
void QS(ForwardIt first, ForwardIt last){
    if (first == last)
        return;
 
    auto pivot = *std::next(first, std::distance(first, last) / 2);

    auto middle1 = std::partition(first, last, 
        [pivot](const &e){return e < pivot;});

    auto middle2 = std::partition(middle1, last, 
        [pivot](const &e){return !(pivot < e);}); 
        
    QS(first, middle1);
    QS(middle2, last);
}

void QuickSort(vector<int> &nums){
	QS(nums.begin(), nums.end());
}

int main() {
//	vector<int> nums = {9, 16, 3, 4, 15, 1, 10, 2, 5, 9, 12};
	vector<int> nums = { 42, 71, 10, 14, 42, 95, 63, 38, 27, 81, 56 };
//	vector<int> nums = {1, 3, 4, 6, 8, 9, 10, 11, 15};
//	vector<int> nums = { 4, 6, 3, 1, 10, 4, 8, 15, 9, 11 };

	printf("Initial array before sorting:\n");
	PrintVector(nums);

	QuickSort(nums);

	printf("Array after sorting:\n");
	PrintVector(nums);
} // end-main