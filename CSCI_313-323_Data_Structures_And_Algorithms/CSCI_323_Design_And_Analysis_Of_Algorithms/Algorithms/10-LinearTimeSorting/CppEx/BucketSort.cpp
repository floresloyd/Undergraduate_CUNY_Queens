#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bucketSort(vector<int>& nums, int numBuckets) {
    int n = nums.size();
    int minVal = *min_element(nums.begin(), nums.end());
    int maxVal = *max_element(nums.begin(), nums.end());
    int numsRange = maxVal - minVal + 1;
    vector<vector<int>> buckets(numBuckets);

    // Put array elements in their respective buckets
    for (auto num: nums) {
        int bucketIdx = (int)(((double)num - minVal) / numsRange * (numBuckets - 1));
        buckets[bucketIdx].push_back(num);
    } // end-for

    // Sort the individual buckets
    for (int i = 0; i < numBuckets; i++)
        sort(buckets[i].begin(), buckets[i].end());

    // Concatenate all the buckets into the original numsay
    int idx = 0;
    for (int i = 0; i < numBuckets; i++)
        for (auto num: buckets[i])
            nums[idx++] = num;
} // end-bucketSort

// Test Code
void BucketSortTest() {
    vector<int> nums = { 40, 15,20, 25, 57, 80, 44, 2,71 };

    cout << "Numbers before sorting: ";
    for (int x : nums) cout << x << ", "; cout << endl;

    bucketSort(nums, 4);

    cout << "Numbers after bucketSort: ";
    for (int x : nums) cout << x << ", "; cout << endl;
} // end-BucketSort

int main(){
    BucketSortTest();

    return 0;
}
