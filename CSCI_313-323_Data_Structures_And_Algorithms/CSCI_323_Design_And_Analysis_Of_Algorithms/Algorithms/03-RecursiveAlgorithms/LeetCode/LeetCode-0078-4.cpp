class Solution {
public:
    // O(2^n), where n is the number of elements in nums
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;

        int n = nums.size();
        int numSubsets = 1<<n;
        for (int i=0; i<numSubsets; i++){
            int num = i;
            result.push_back({});
            for (int index=n-1; num != 0; index--, num >>= 1){
                if (num & 1)
                    result.back().push_back(nums[index]);
            } // end-for
        } // end-for

        return result;
    }
};