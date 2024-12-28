class Solution {
    // O(n^2) algorithm with O(1) extra space
    public boolean containsDuplicate(int[] nums) {
        for (int i=1; i<nums.length; i++){
            for (int j=0; j<i; j++){
                if (nums[i] == nums[j]) return true;
            } //end-for
        } // end-for

        return false;        
    }
}