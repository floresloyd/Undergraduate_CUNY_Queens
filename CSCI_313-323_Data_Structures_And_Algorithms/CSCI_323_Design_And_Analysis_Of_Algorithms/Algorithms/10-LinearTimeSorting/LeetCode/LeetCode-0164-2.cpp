class Solution {
public:
    /// O(n) algorithm with O(n) extra space
    int maximumGap(vector<int>& nums){
        if (nums.size() < 2) return 0;

        int minNum = *std::min_element(nums.begin(), nums.end());
        int maxNum = *std::max_element(nums.begin(), nums.end());

        int n = nums.size();
        int bucketSize = std::max(1, (maxNum - minNum) / n);
        int numBuckets = ((maxNum - minNum) / bucketSize) + 1;

        struct Bucket {
            bool used = false;
            int minVal = INT_MAX;
            int maxVal = INT_MIN;
        };
        vector<Bucket> buckets(numBuckets);
        
        for (auto &num: nums) {
            int bucket = (num - minNum) / bucketSize;
            buckets[bucket].used = true;
            buckets[bucket].minVal = std::min(num, buckets[bucket].minVal);
            buckets[bucket].maxVal = std::max(num, buckets[bucket].maxVal);
        } // end-for

        int prevMax = minNum, result = 0;
        for (auto &bucket: buckets) {
            if (not bucket.used) continue;

            result = max(result, bucket.minVal - prevMax);
            prevMax = bucket.maxVal;
        } // end-for

        return result;
    } // end-maximumGap
};