class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int W = std::accumulate(nums.begin(), nums.end(), 0);
        if (W & 1) return false;
        W = W/2; 
        int n = nums.size();
        vector<bool> T(W+1, false);
        T[0] = true;
        for (int i=1; i<=n; i++){
            int num = nums[i-1];
            for (int j=W-num; j>=0; j--){
                if (T[j]) T[j+num] = true;
            } // end-for
        } // end-for
        
        return T[W];
    } // end-canPartition
};