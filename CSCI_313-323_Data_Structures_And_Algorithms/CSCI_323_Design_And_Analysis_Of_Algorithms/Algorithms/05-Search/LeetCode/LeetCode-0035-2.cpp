class Solution {
public:
    // bisect_left
    int searchInsert(vector<int>& nums, int target) {
        auto iter = std::lower_bound(nums.begin(), nums.end(), target);
        return std::distance(nums.begin(), iter);
    } // end-searchInsert
};