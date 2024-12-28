#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Radix Sort
void radixSort(vector<int>& nums) {
    // Find the maximum number to know number of digits
    int max = *std::max_element(nums.begin(), nums.end());

    // Do counting sort for every digit
    int n = nums.size();
    vector<int> out(n);
    // 342/100=3%10 =3 
    // exp=100
    for (int exp = 1; max / exp > 0; exp *= 10) {
        vector<int> count(10, 0);

        // Count the digits
        for (auto num: nums)
            count[(num / exp) % 10]++;

        // Calculate the indices of the elements in the output array
        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];

        // Build the output array
        for (int i = n - 1; i >= 0; i--) {
            int digit = (nums[i] / exp) % 10;
            out[--count[digit]] = nums[i];
        } // end-for

        // Copy from out to nums
        nums = out;
    } // end-for
}

void RadixSortTest() {
    vector<int> nums = { 576, 494, 94, 296, 8, 176, 4};

    cout << "Numbers before sorting: ";
    for (int x : nums) cout << x << ", "; cout << endl;

    radixSort(nums);

    cout << "Numbers after radixSort: ";
    for (int x : nums) cout << x << ", "; cout << endl;
} // end-RadixSortTest

int main(){
    RadixSortTest();
}
