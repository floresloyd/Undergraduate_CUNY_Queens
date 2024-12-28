class Solution {
    /// O(nlogn + klogn) algorithm with O(n) extra space
    public long maxKelements(int[] nums, int k) {
        /// Create a max PQ and insert all numbers
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>((x, y)->Integer.compare(y, x));
        for (var num: nums) pq.offer(num);

        long result = 0;
        while (k-- > 0){
            var val = pq.poll();
            result += val;
            pq.offer((val+2)/3);
        } // end-while
        return result;        
    }
}
