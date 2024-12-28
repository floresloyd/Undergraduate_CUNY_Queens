class Solution {
public:
    // O(n + klogn + nlogn) algorithm with O(n) extra space
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> Q(gifts.begin(), gifts.end());

        while (k--){
            int num = Q.top();
            Q.pop();
            Q.push((int)sqrt(num));
        } // end-while

        int64_t result = 0;
        while (Q.size()){
            int num = Q.top();
            Q.pop();
            result += num;
        } // end-while
        return result;
    } // end-pickGifts
};