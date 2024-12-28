class Solution {
    /// An O(nxm) algorithm that uses O(m) extra space (monotonic stack)
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        Stack<Integer> S = new Stack<>();

        int[] nextGreater = new int[nums2.length];
        for (int i=nums2.length-1; i>=0; i--){
            while (!S.isEmpty() && nums2[i] >= S.peek()) S.pop();

            if (S.isEmpty()) nextGreater[i] = -1;
            else             nextGreater[i] = S.peek();

            S.push(nums2[i]);
        } //end-for

        // Find the index of nums1[i] inside nums2, and push the nextGreater to the result
        int [] result = new int[nums1.length];
        for (int i=0; i<nums1.length; i++){
            for (int j=0; j<nums2.length; j++){
                if (nums1[i] == nums2[j]){
                    result[i] = nextGreater[j];
                    break;
                } //end-if
            } //end-for
        } //end-for

        return result;
    } //end-nextGreaterElement
}