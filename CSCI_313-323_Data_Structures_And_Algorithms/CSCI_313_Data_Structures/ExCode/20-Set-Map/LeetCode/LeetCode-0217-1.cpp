class Solution {
public:
    // O(n^2) algorithm with O(1) extra space
    bool containsDuplicate(vector<int>& nums) {
        for (size_t i=1; i<nums.size(); i++){
            for (int j=0; j<i; j++){
                if (nums[i] == nums[j]) return true;
            } //end-for
        } // end-for

        return false;
    } //end-containsDuplicate
};