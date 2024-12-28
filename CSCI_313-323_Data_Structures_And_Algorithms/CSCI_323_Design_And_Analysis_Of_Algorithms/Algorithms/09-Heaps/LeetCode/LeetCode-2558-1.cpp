class Solution {
public:
    // O(kn) algorithm with O(1) extra space
    long long pickGifts(vector<int>& gifts, int k) {
        int n = gifts.size();
        while (k--){
            auto iter = std::max_element(gifts.begin(), gifts.end());
            *iter = sqrt(*iter);
        } // end-while

        int64_t result = 0;
        for (auto num: gifts)
            result += num;
        return result;
    } // end-pickGifts
};