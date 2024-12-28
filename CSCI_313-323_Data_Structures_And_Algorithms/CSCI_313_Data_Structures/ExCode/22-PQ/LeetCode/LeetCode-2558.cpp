class Solution {
public:
    /// O(klogn + nlogn) algorithm with O(n) extra space
    long long pickGifts(vector<int>& gifts, int k) {
        std::priority_queue<int> Q(gifts.begin(), gifts.end());
        while (k--){
            auto num = Q.top();
            Q.pop();
            Q.push((int)sqrt(num));
        } // end-while

        int64_t result = 0;
        while (Q.size()){
            auto num = Q.top();
            Q.pop();
            result += num;
        } // end-while

        return result;
    } // end-pickGifts
};