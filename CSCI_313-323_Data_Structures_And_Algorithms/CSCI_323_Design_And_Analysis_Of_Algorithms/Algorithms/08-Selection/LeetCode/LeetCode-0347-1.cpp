class Solution {
public:
    // O(n+m+mlogm) algorithm with O(m) extra space, where m is the number of unique elements in nums
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> num_freq;
        for (auto num: nums)
            num_freq[num]++;

        vector<int> result;
        for (auto [num, freq]: num_freq)
            result.push_back(num);

        auto cmp = [&](int one, int two){
            return num_freq[one] > num_freq[two];
        };
        std::sort(result.begin(), result.end(), cmp);
        result.resize(k);
        return result;
    }
};