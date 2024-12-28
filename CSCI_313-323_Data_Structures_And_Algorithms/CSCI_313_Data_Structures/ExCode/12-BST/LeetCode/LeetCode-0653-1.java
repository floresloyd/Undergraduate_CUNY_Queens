/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    /// Here is an O(n) time algorithm that uses O(n) extra space
    /// Simply do an in-order traversal and get the keys in sorted order
    /// Then simply do a walk over the sorted array using two pointers,
    /// one starting from the front, and the other starting from the end
    private void getSorted(TreeNode root, List<Integer> nums){
        if (root == null) return;
        getSorted(root.left, nums);
        nums.add(root.val);
        getSorted(root.right, nums);
    } //end-getSorted

    public boolean findTarget(TreeNode root, int k) {
        List<Integer> nums = new ArrayList<>();

        getSorted(root, nums);
        if (nums.size() < 2) return false;

        int i=0, j=nums.size()-1;
        while (i<j){
            int sum = nums.get(i) + nums.get(j);
            if (sum == k) return true;
            if (sum < k) i++;
            else         j--;
        } //end-while

        return false;        
    }
}