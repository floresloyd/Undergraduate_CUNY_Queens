class Solution {
public:
    /// O(klogn) algorithm with O(n) extra space
    int minStoneSum(vector<int>& piles, int k) {
        int total = std::accumulate(piles.begin(), piles.end(), 0);
        priority_queue<int> Q(piles.begin(), piles.end());   // Max-heap
        
        while (k-->0){
            auto num = Q.top(); Q.pop();
            Q.push(num-num/2);
            total -= num/2;
        } // end-while
        
        return total;
    } // end-minStoneSum
};