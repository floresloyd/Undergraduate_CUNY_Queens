class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int W = std::accumulate(nums.begin(), nums.end(), 0);
        if (W & 1) return false;
        W = W/2; 
        int n = nums.size();
        vector<vector<int>> T(n+1, vector<int>(W+1, 0));
        for (int i=1; i<=n; i++){
            int num = nums[i-1];
            for (int j=1; j<=W; j++){
                int leave_it = T[i-1][j];
                int take_it = 0;
                if (num <= j) take_it = num + T[i-1][j-num];
                T[i][j] = std::max(take_it, leave_it);
            } // end-for
        } // end-for

        return T[n][W] == W;
    } // end-canPartition
};