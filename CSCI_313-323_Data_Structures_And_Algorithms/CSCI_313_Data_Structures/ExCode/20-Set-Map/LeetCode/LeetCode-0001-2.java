class Solution {
    /// O(n) algorithm with O(n) extra space
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> myMap = new HashMap();

        myMap.put(nums[0], 0);
        for (int i=1; i<nums.length; i++){
            Integer val = myMap.get(target-nums[i]);
            if (val != null)
                return new int[]{val, i};

            myMap.put(nums[i], i);  // Insert this number to the map
        } //end-for

        return new int[]{-1, -1};
    } //end-twoSum
}
