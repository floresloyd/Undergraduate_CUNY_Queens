#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

/// --------------------------------------------------
/// O(logN) algorithm for binary search in a sorted array
///
int BinarySearch(vector<int>& nums, int key) {
    int left = 0;
    int right = (int)nums.size() - 1;

    while (left <= right) {
        int middle = left + (right-left) / 2;             // Index of the key to test against
        if (key == nums[middle]) return middle;           // Key found. Return the index
        else if (key < nums[middle]) right = middle - 1;  // Eliminate the right side
        else left = middle + 1;                           // Eliminate the left side        
    } //end-while

    return -1;   // Key not found
} // end-BinarySearch

///-----------------------------------------------------
/// O(logN) binary search
/// 
int RecursiveBinarySearch(vector<int>& nums, int key, int left, int right) {
	if (left > right) return -1;

	int middle = left + (right-left) / 2; 
	if (key == nums[middle]) return middle;
	if (key < nums[middle]) return RecursiveBinarySearch(nums, key, left, middle - 1);
	return RecursiveBinarySearch(nums, key, middle + 1, right);
} //end-RecursiveBinarySearch

int main() {
    vector<int> nums = {3, 8, 10, 11, 20, 50, 55, 60, 65, 70, 72, 90, 91, 94, 96, 99};

    printf("Index of 55: %d\n", BinarySearch(nums, 55));
    printf("Index of 55: %d\n", RecursiveBinarySearch(nums, 55, 0, nums.size()-1));

    printf("Index of 57: %d\n", BinarySearch(nums, 57));
    printf("Index of 57: %d\n", RecursiveBinarySearch(nums, 57, 0, nums.size()-1));
    
	return 0;
} // end-main
