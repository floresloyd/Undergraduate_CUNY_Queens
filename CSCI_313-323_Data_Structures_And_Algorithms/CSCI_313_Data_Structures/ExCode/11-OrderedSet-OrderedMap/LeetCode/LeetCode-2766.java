class Solution {
    /// O(nlogn) algorithm with O(n) extra space
    public List<Integer> relocateMarbles(int[] nums, int[] moveFrom, int[] moveTo) {
        TreeSet<Integer> marbles = new TreeSet<>();
        for (var num: nums) marbles.add(num);

        for (int i=0; i<moveFrom.length; i++){
            if (moveFrom[i] == moveTo[i]) continue;
            marbles.remove(moveFrom[i]);
            marbles.add(moveTo[i]);
        } // end-for

        return new ArrayList<Integer>(marbles);
    }
}