class Solution {
public:
    /// O(n) algorithm with O(1) extra space
    /// Single pass algorithm (more efficient version)
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while (i<n and nums[i] == 0) i++;
        int j=n-1;
        while (j>i and nums[j] == 2) j--;
        int k = i;
        while (true){
            while (k <= j and nums[k] == 1) k++;
            if (k > j) break;
            
            if (nums[k] == 0)
                std::swap(nums[i++], nums[k++]);
            else
                std::swap(nums[j--], nums[k]);
        } // end-for
    } // end-sortColors
};