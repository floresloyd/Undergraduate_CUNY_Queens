class Solution {
public:
    // O(n + k + (m-k)*logk) algorithm with O(m) extra space, where m is the number of unique numbers
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> num_freq;
        for (auto num: nums)
            num_freq[num]++;

        auto cmp = [&](int one, int two){
            return num_freq[one] > num_freq[two];
        };
        vector<int> result;
        auto iter = num_freq.begin();
        for (; k--; ++iter)
            result.push_back(iter->first);

        std::make_heap(result.begin(), result.end(), cmp);
        for (; iter!=num_freq.end(); ++iter){
            if (iter->second > num_freq[result[0]]){
                std::pop_heap(result.begin(), result.end(), cmp);
                result.back() = iter->first;
                std::push_heap(result.begin(), result.end(), cmp);
            } // end-if
        } // end-for

        return result;
    }
};