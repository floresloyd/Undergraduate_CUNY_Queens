class Solution {
public:
    /// O(n) algorithm with O(1) extra space
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;
        while (true){
            while (i<j and nums[i]%2 == 0) i++;
            while (i<j and nums[j]%2 == 1) j--;
            if (i>=j) break;
            std::swap(nums[i++], nums[j--]);
        } // end-while
        return nums;
    } // end-sortArrayByParity
};