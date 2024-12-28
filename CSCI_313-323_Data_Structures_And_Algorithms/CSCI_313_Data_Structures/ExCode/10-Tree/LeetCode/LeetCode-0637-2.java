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
    /// Do a level-by-level traversal using a queue
    /// Do not attach "level" to each node in the queue
    /// But how do we determine the end of a level? The idea is to push
    /// a null pointer to the queue to mark the end of a level
    public List<Double> averageOfLevels(TreeNode root) {
        List<Double> result = new ArrayList<>();
        if (root == null) return result;

        Queue<TreeNode> Q = new LinkedList<>();
        Q.add(root);
        Q.add(null);     // This marks the end of the nodes at this level

        double sum = 0;   // Sum of the elements at this level
        int n = 0;        // # of nodes at this level

        while (!Q.isEmpty()){
            TreeNode p = Q.remove();

            // Have we reached the end of a level?
            if (p == null){
                result.add(sum/n);
                sum = n = 0;
                if (!Q.isEmpty()) Q.add(null);  // Mark the end of the next level

            } else {
                n++;
                sum += p.val;
                if (p.left != null) Q.add(p.left);
                if (p.right != null) Q.add(p.right);
            } //end-else
        } //end-while

        return result;        
    }
}