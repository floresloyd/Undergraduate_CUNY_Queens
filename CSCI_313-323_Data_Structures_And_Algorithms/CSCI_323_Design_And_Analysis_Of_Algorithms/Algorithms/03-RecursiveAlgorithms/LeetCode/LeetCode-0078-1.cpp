class Solution {
public:
    // O(2^n), where n is the number of elements in nums
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;

        function<void(int)> solve = [&](int n){
            if (n == 0){
                result.push_back({});
                return;
            } // end-if

            solve(n-1);

            int numSubsets = result.size();
            for (int i=0; i<numSubsets; i++){
                result.push_back(result[i]);
                result.back().push_back(nums[n-1]);
            } // end-for
        }; // end-solve

        solve(nums.size());
        return result;
    }
};