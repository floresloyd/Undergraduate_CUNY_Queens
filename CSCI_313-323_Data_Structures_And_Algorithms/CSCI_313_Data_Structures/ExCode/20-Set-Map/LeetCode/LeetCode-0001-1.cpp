class Solution {
public:
    /// O(n^2) algorithm with O(1) extra space: Check all (i, j) pairs
	vector<int> twoSum(vector<int>& nums, int target) {
        for (int i=0; i<nums.size()-1; i++){
            for (int j=i+1; j<nums.size(); j++){
                if (nums[i] + nums[j] == target){
                    return vector<int>{i, j};
                } //end-if
            } //end-for
        } //end-for

        return {-1, -1};  // No pair adds up to the target
    } //end-twoSum
};
