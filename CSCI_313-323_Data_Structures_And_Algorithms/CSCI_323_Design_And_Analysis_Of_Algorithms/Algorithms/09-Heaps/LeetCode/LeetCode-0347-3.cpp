class Solution {
public:
    // O(n + mlogk + klogk) algorithm with O(m+k) extra space, where m is the number of unique numbers
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> num_freq;
        for (auto num: nums)
            num_freq[num]++;

        auto cmp = [&](int one, int two){
            return num_freq[one] > num_freq[two];
        };
        priority_queue<int, vector<int>, decltype(cmp)> Q(cmp);
        auto iter = num_freq.begin();
        for (; k--; ++iter)
            Q.push(iter->first);

        for (; iter!=num_freq.end(); ++iter){
            if (iter->second > num_freq[Q.top()]){
                Q.pop();
                Q.push(iter->first);
            } // end-if
        } // end-for

        vector<int> result;
        while (Q.size()){
            result.push_back(Q.top());
            Q.pop();
        } // end-while
        return result;
    }
};