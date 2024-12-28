class Solution {
public:
    /// Brute-force recursive solution: Gets TLE
    pair<int, int> solve(vector<int> &nums, int left, int right){
        if (left == right){return {0, nums[left]};};
        if (left+1 == right){
            return {nums[left]*nums[right], std::max(nums[left], nums[right])};
        } // end-if

        int minVal = INT_MAX;
        int maxNum = INT_MIN;
        for (int i=left+1; i<=right; i++){
            pair<int, int> sol1 = solve(nums, left, i-1);
            pair<int, int> sol2 = solve(nums, i, right);
            
            int sol = sol1.first+sol2.first+sol1.second*sol2.second;
            if (sol < minVal){
                minVal = sol;
                maxNum = std::max(sol1.second, sol2.second);
            } // end-if            
        } // end-for
        return {minVal, maxNum};
    } // end-solve
    
    int mctFromLeafValues(vector<int>& nums) {
        pair<int, int> result = solve(nums, 0, nums.size()-1);
        return result.first;
    } // end-mctFromLeafValues
};