class Solution {
public:
    // O(2^n), where n is the number of elements in nums
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;

        function<void(int, vector<int>)> solve = [&](int n, vector<int> subset){
            if (n == 0){
                result.push_back(subset);
                return;
            } // end-if

            solve(n-1, subset); // leave it

            subset.push_back(nums[n-1]); // take it
            solve(n-1, subset);
        }; // end-solve

        solve(nums.size(), vector<int>{});
        return result;
    }
};