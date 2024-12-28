class Solution {
public:
    /// O(n) algorithm with O(1) extra space
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        for (int i=0, j=1; i<n && j<n; i+=2, j+=2){
            while (i<n && nums[i]%2 == 0) i+=2;
            if (i >= n) break;
            
            while (j<n && nums[j]%2 == 1) j+=2;
            if (j >= n) break;

            std::swap(nums[i], nums[j]);
        } // end-while
        
        return nums;        
    } // end-sortArrayByParityII
};