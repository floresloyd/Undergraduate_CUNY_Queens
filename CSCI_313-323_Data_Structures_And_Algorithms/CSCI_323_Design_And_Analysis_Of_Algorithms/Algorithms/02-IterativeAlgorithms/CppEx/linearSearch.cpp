#include <stdio.h>
#include <vector>
#include <iostream>
#include <cstdint>

using namespace std;

/// --------------------------------------------------
/// O(N) algorithm for forward linear search in an unsorted array
///
int LinearSearch(vector<int>& nums, int key) {
    for (uint32_t i = 0; i < nums.size(); i++) {
        if (nums[i] == key) return i;
    } // end-for

    return -1;
} // end-LinearSearch

int main() {
    vector<int> nums = { 9, 4, 10, 1, 20, 12, 3, 99, 65, 52, 25, 11, 91, 24, 20 };
    printf("Index of 20: %d\n", LinearSearch(nums, 20));
    printf("Index of 57: %d\n", LinearSearch(nums, 57));

	return 0;
} // end-main
