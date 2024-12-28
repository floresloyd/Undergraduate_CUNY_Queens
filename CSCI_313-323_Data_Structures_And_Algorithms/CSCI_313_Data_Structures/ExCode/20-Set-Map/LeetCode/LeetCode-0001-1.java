class Solution {
    /// O(n^2) algorithm with O(1) extra space
    public int[] twoSum(int[] nums, int target) {
        for (int i=0; i<nums.length-1; i++){
            for (int j=i+1; j<nums.length; j++){
                if (nums[i] + nums[j] == target){
                    return new int[]{i, j};
                } //end-if
            } //end-for
        } //end-for

        return new int[]{-1, -1};  // No pair adds up to the target
    } //end-twoSum
} // end-solution
