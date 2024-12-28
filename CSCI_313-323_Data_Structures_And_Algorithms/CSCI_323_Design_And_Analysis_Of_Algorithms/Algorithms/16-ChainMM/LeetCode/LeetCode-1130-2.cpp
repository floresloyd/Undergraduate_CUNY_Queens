class Solution {
public:
    /// Top-down DP: This is a variant of chain matrix multiplication
    pair<int, int> solve(vector<int> &nums, int left, int right,
                        vector<vector<pair<int, int>>> &T){        
        if (left == right){return {0, nums[left]};};
        if (left+1 == right){
            return {nums[left]*nums[right], std::max(nums[left], nums[right])};
        } // end-if
        if (T[left][right].first != -1)
            return T[left][right];

        int minVal = INT_MAX;
        int maxNum = INT_MIN;
        for (int i=left+1; i<=right; i++){
            pair<int, int> sol1 = solve(nums, left, i-1, T);
            pair<int, int> sol2 = solve(nums, i, right, T);
            
            int sol = sol1.first+sol2.first+sol1.second*sol2.second;
            if (sol < minVal){
                minVal = sol;
                maxNum = std::max(sol1.second, sol2.second);
            } // end-if            
        } // end-for
        return T[left][right] = {minVal, maxNum};
    } // end-solve
    
    int mctFromLeafValues(vector<int>& nums) {
        int n = nums.size();
        vector<vector<pair<int, int>>> T(n, vector<pair<int, int>>(n, {-1, -1}));
        pair<int, int> result = solve(nums, 0, n-1, T);
        return result.first;
    } // end-mctFromLeafValues
};