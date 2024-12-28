#include <stdio.h>
#include <vector>
#include <iostream>
#include <cstdint>

using namespace std;

/// O(N) algorithm to compute the summation of N numbers
int Sum(vector<int> &nums) {
    int sum = 0;
    int32_t i = 0;
    while (i < nums.size()) {
        sum += nums[i];
        i++;
    } //end-for

    return sum;
} //end-Sum

int main() {
    vector<int> nums = { 3, 9, 6, 5, 2 };
    int result = Sum(nums);
    printf("Sum of the numbers in nums: %d\n", result);

    return 0;
} // end-main