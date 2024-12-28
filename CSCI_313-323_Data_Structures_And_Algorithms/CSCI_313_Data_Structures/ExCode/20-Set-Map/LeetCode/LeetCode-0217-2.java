class Solution {
    // O(n) algorithm with O(n) extra space
    public boolean containsDuplicate(int[] nums) {
        Set<Integer> mySet = new HashSet<>();

        for (var num: nums){
            if (mySet.contains(num)) // Expected O(1)
                return true;
            mySet.add(num); // Expected O(1)
        } // end-for

        return false;
    }
}