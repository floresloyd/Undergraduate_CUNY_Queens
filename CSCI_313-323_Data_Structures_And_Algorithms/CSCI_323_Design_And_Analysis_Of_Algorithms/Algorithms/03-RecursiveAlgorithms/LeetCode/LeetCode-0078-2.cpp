class Solution {
public:
    /// This recursive algorithm makes just 2^n recursive calls
    /// Each time we enter the recursion, we create one subset
    /// When you expand the recursion tree, we see that the root
    /// corresponds to the empty set, all subsets with 1 element
    /// are children of this root, all subsets with 2 elements
    /// are children of the subsets with 1 element, etc.
    /// This means that as we go down the recursion tree,
    /// we create subsets with one more element. That is, at the kth level
    /// we have all subsets with "k" elements. Thus, at the leaf,
    /// we have only 1 subset; the one containing ALL elements
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        vector<int> subset;

        function<void(int)> solve = [&](int index){
            result.push_back(subset);            
            for (; index<n; index++){
                subset.push_back(nums[index]);
                solve(index+1);
                subset.pop_back();
            } // end-for
        }; // end-solve

        solve(0);

        return result;
    }
};