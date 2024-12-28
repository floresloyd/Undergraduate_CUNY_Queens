class Solution {
public:
    /// O(nlogn) algorithm with O(1) extra space
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        std::sort(nums.begin(), nums.end());
        ++nums.back();
        for (int i=0; i<n; i++)
            if (nums[i] != i+1)
                return false;
        return true;
    }
};