class Solution {
public:
    /// O(n) algorithm with O(1) extra space
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int k = 0;
        vector<int> colors = {0, 1};
        for (auto color: colors){
            for (; k<n and nums[k] == color; k++);
            for (int i=k; i<n; i++){
                if (nums[i] == color)
                    std::swap(nums[k++], nums[i]);
            } // end-for
        } // end-for
    } // end-sortColors
};