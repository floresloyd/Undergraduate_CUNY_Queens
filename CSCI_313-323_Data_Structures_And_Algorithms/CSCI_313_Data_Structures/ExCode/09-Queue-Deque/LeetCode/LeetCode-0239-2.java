class Solution {
    /// O(n) algorithm with O(k) extra space
    public int[] maxSlidingWindow(int[] nums, int k) {
        Deque<Integer> dq = new LinkedList<>();
        int [] result = new int[nums.length-k+1];

        for (int i=0; i<nums.length; i++){
            var curr = nums[i];
            
            // Remove the number that got out of the window
            if (!dq.isEmpty() && dq.peekFirst() <= i-k) dq.removeFirst();
            
            // Remove numbers that cannot be max. in the future
            while (!dq.isEmpty() && curr >= nums[dq.peekLast()]) dq.removeLast();  
                      
            // Push the current index
            dq.addLast(i);
            
            // If the window size is "k", push the max. value to the result
            if (i >= k-1)
                result[i-k+1] = nums[dq.peekFirst()];
        } //end-for

        return result;
    }
}