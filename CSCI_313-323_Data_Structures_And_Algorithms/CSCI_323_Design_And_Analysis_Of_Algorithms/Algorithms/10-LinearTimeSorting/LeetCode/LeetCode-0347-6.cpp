class Solution {
public:
    // O(n+mlogm) algorithm with O(m) extra space, where m is the number of unique elements
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> num_freq;
        for (auto num: nums)
            num_freq[num]++;

        map<int, vector<int>> lut;
        for (auto &[num, freq]: num_freq)
            lut[freq].push_back(num);

        vector<int> result;
        for (auto iter=lut.rbegin(); k; ++iter){
            for (auto num: iter->second){
                result.push_back(num);
                if (--k == 0) break;
            } // end-for
        } // end-for

        return result;
    } // end-topKFrequent
};