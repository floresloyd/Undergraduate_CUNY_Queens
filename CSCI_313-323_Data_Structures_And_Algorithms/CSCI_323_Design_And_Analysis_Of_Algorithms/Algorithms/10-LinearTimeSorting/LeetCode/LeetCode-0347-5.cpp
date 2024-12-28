class Solution {
public:
    // O(n+m) algorithm with O(n+m) extra space, where m is the number of unique elements
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> num_freq;
        for (auto num: nums)
            num_freq[num]++;

        int maxFreq = 1;
        for (auto &[_, freq]: num_freq)
            maxFreq = std::max(maxFreq, freq);
            
        vector<vector<int>> lut(maxFreq+1);
        for (auto &[num, freq]: num_freq)
            lut[freq].push_back(num);

        vector<int> result;
        for (int i=maxFreq; k; i--){
            for (auto num: lut[i]){
                result.push_back(num);
                if (--k == 0) break;
            } // end-for
        } // end-for

        return result;
    } // end-topKFrequent
};