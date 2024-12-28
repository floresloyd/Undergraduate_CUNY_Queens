class Solution {
    /// O(klogn + nlogn) algorithm with O(n) extra space
    public long pickGifts(int[] gifts, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>((x, y)->y-x);
        for (var gift: gifts) pq.offer(gift);

        while (k-- > 0){
            var num = pq.poll();
            pq.offer((int)Math.sqrt(num));
        } // end-while

        long result = 0;
        for (var num: pq) result += num;
        return result;
    }
}