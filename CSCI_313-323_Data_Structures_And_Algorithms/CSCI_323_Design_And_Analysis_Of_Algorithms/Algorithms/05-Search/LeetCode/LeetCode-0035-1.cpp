class Solution {
public:
    // lower_bound/bisect_left
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        while (left <= right){
            int middle = left + (right-left)/2;
            if (nums[middle] < target) left = middle+1;
            else right = middle-1;
        } // end-while
        return left;
    } // end-searchInsert
};