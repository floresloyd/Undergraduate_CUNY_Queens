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
    /// This time we will simply do a recursive tree traversal, and pass the level
    /// of the node as a parameter to the function. We will simply find the sum
    /// of all nodes and their count at each level. Finally, we will use
    /// this information to compute the averages

    class Pair {
        double sum; 
        int count;
        public Pair(double sum, int count){
            this.sum = sum;
            this.count = count;
        }
    }

    void dfs(TreeNode root, int level, List<Pair> levelSums){
        if (root == null) return;

        if (level >= levelSums.size()) 
            levelSums.add(new Pair(root.val, 1));
        else {
            levelSums.get(level).sum += root.val;    // Increment sum
            levelSums.get(level).count++;            // Increment # of nodes
        } //end-else

        dfs(root.left, level+1, levelSums);
        dfs(root.right, level+1, levelSums);
    } //end-dfs   

    public List<Double> averageOfLevels(TreeNode root) {
        List<Double> result = new ArrayList<>();
        if (root == null) return result;

        List<Pair> levelSums = new ArrayList<>();        
        dfs(root, 0, levelSums);

        for (var pair: levelSums){
            result.add(pair.sum/pair.count);
        } //end-for

        return result;
    }
}