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
    private boolean validate(TreeNode root, long leftVal, long rightVal){
        if (root == null) return true;
        if (root.val < leftVal || root.val > rightVal) return false;
        if (!validate(root.left, leftVal, root.val-1L)) return false;
        return validate(root.right, root.val+1L, rightVal);
    } // end-validate

    public boolean isValidBST(TreeNode root) {
        return validate(root, Long.MIN_VALUE, Long.MAX_VALUE);        
    }
}