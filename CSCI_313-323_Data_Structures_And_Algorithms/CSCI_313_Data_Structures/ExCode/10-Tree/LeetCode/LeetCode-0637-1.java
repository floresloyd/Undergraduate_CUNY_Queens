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
    public List<Double> averageOfLevels(TreeNode root) {
        List<Double> result = new ArrayList<>();
        if (root == null) return result;

        // <node, level>
        record Pair(TreeNode node, int level){};
        Queue<Pair> Q = new LinkedList<>();
        int currentLevel = 0;
        Q.add(new Pair(root, currentLevel));

        double sum = 0;   // Sum of the elements at this level
        int n = 0;        // # of nodes at this level

        while (!Q.isEmpty()){
            var pair = Q.remove();
            var p = pair.node();
            var level = pair.level();

            // Did we go to the next level?
            if (level > currentLevel){
                result.add(sum/n);
                sum = n = 0;
                currentLevel = level;
            } // end-if

            n++;
            sum += p.val;

            if (p.left != null) Q.add(new Pair(p.left, level+1));
            if (p.right != null) Q.add(new Pair(p.right, level+1));
        } //end-while

        // Push the average for the last level
        if (n > 0) result.add(sum/n);

        return result;        
    }
}