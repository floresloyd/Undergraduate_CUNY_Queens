class Solution {
public:
    /// O(n) algorithm with O(1) extra space
    /// Single pass algorithm (clean version)
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        for (int i=0, j=n-1, k=0; k<=j;){
            if (nums[k] == 1) k++;
            else if (nums[k] == 0)
                std::swap(nums[i++], nums[k++]);
            else
                std::swap(nums[j--], nums[k]);
        } // end-for
    } // end-sortColors
};