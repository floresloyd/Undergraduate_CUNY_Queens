class Solution {
public:
    /// O(NlogN) algorithm with O(1) extra space
    bool containsDuplicate(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        
        // Walk over the list & compare consecutive numbers
        for (int i=1; i<nums.size(); i++)
            if (nums[i] == nums[i-1])
                return true;

        return false;        
    } // end-containsDuplicate
};