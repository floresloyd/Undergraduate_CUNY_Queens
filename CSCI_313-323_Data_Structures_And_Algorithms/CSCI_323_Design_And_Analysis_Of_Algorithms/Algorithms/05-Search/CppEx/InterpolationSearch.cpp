#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

/// --------------------------------------------------
/// Interpolation Search
/// Best case: O(1)
/// Average case: O(loglogN)
/// Worst case: O(N)
///
int InterpolationSearch(vector<int>& nums, int key) {
    int left = 0;
    int right = (int)nums.size() - 1;

    int numProbes = 0;
    while ((nums[right] != nums[left]) && (key >= nums[left]) && (key <= nums[right])) {
        int middle = left + ((right-left)*(key-nums[left]) / (nums[right]-nums[left]));

        printf("Inter. search. probe count: %d, left: %d, middle: %d, right: %d, nums[middle]: %d\n", 
                ++numProbes, left, middle, right, nums[middle]);

        if (nums[middle] < key)
            left = middle + 1;
        else if (key < nums[middle])
            right = middle - 1;
        else
            return middle;
    }

    return key == nums[left]? left: -1;
} // end-InterpolationSearch

int main() {
    vector<int> nums = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60,65, 70, 75, 80};

    printf("Index of 10: %d\n", InterpolationSearch(nums, 10));
    printf("---------------------------------------------\n");

    printf("Index of 40: %d\n", InterpolationSearch(nums, 40));
    printf("---------------------------------------------\n");

    printf("Index of 57: %d\n", InterpolationSearch(nums, 57));
    printf("---------------------------------------------\n");

    vector<int> nums2 = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60,65, 70, 75, 5000};
    printf("Index of 75: %d\n", InterpolationSearch(nums2, 75));

	return 0;
} // end-main
