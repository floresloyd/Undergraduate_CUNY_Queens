#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// O(logn) algorithm to compute the upper_bound
int myUpperBound(vector<int>& nums, int key) {
    int left = 0;
    int right = (int)nums.size() - 1;

    while (left <= right) {
        int middle = left + (right-left) / 2; 
        if (nums[middle] <= key) left = middle+1;  // Evaluate the predicate: element < key
        else right = middle-1;
    } //end-while

    return left;
} // end-myUpperBound

int main() {
    vector<int> nums = {3, 8, 10, 11, 20, 20, 20, 50, 65, 70, 72, 90, 91, 94, 96, 99};

    printf("Index of 20: %d\n", myUpperBound(nums, 20));
    printf("Index of 60: %d\n", myUpperBound(nums, 60));
    printf("Index of 100: %d\n", myUpperBound(nums, 100));
    printf("--------------------------------------------\n");

    // Use C++ upper_bound
    printf("Doing the same calculation using upper_bound function\n");
    auto iter1 = upper_bound(nums.begin(), nums.end(), 20);
    printf("Index of 20: %d\n", std::distance(nums.begin(), iter1));

    auto iter2 = upper_bound(nums.begin(), nums.end(), 60);
    printf("Index of 60: %d\n", std::distance(nums.begin(), iter2));

    auto iter3 = upper_bound(nums.begin(), nums.end(), 100);
    printf("Index of 100: %d\n", std::distance(nums.begin(), iter3));

	return 0;
} // end-main
