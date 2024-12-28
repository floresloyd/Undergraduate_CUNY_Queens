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
    /// O(n) algorithm with O(d) extra space
    /// -1 indicates that the tree is NOT balanced
    private int computeDepth(TreeNode root){
        if (root == null) return 0;
        int leftDepth = computeDepth(root.left);
        if (leftDepth < 0) return -1;

        int rightDepth = computeDepth(root.right);
        if (rightDepth < 0) return -1;

        if (Math.abs(leftDepth-rightDepth) > 1) return -1;
        return 1 + Math.max(leftDepth, rightDepth);
    }

    public boolean isBalanced(TreeNode root) {
        return computeDepth(root) >= 0;
    }
}