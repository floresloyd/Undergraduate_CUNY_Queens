class Solution {
public:
    // O(n + klogn) algorithm with O(1) extra space
    long long pickGifts(vector<int>& gifts, int k) {
        std::make_heap(gifts.begin(), gifts.end());

        while (k--){            
            int num = gifts[0];
            std::pop_heap(gifts.begin(), gifts.end());

            gifts.back() = (int)sqrt(num);
            std::push_heap(gifts.begin(), gifts.end());
        } // end-while

        return std::accumulate(gifts.begin(), gifts.end(), 0L);
    } // end-pickGifts
};