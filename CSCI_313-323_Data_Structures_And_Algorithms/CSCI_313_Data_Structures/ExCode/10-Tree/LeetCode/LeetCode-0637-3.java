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
    /// Consider the state of the Q at the end of an iteration
    /// Assume we just finished processing a level
    /// What is the current content of the Q? All nodes at the next level
    /// So, we will simply have a for loop to process the nodes at the next level!
    public List<Double> averageOfLevels(TreeNode root) {
        List<Double> result = new ArrayList<>();
        if (root == null) return result;

        Queue<TreeNode> Q = new LinkedList<>();
        Q.add(root);
        
        while (!Q.isEmpty()){
            int n = Q.size();  // # of nodes at this level
            double sum = 0;    // Sum of the node values at this level
            
            for (int i=0; i<n; i++){
                var p = Q.remove();
                sum += p.val;
                if (p.left != null) Q.add(p.left);
                if (p.right != null) Q.add(p.right);                   
            } // end-for

            result.add(sum/n);
        } //end-while

        return result;
    }
}