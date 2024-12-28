class Solution {
public:
    /// Boils down to the subset sum problem
    /// We simply compute the items to be placed
    /// in each subset, and take their difference
     int lastStoneWeightII(vector<int>& stones) {
        int total = std::accumulate(stones.begin(), stones.end(), 0);
        int W = total/2;
        
        // Fill a knapsack of size W. Bottom-up DP
        int n = stones.size();
        vector<int> T(W+1, 0);
        for (int i=1; i<=n; i++){
            int weight = stones[i-1];
            for (int j=W; j>=weight; j--){
                int take = weight + T[j-weight];                
                int leave = T[j];
                T[j] = std::max(take, leave);
            } // end-for         
        } // end-for

        return total - 2*T[W];
    } // end-lastStoneWeightII
};