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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<>();
        if (root == null) return result;
        
        Queue<TreeNode> Q = new LinkedList<>();
        Q.add(root);
                    
        while (!Q.isEmpty()){
            int n = Q.size();  // # of nodes at this level
            
            // Add a new list to the end of the result
            result.add(new ArrayList<>());
            int index = result.size()-1;
            
            for (int i=0; i<n; i++){
                var p = Q.remove();
                result.get(index).add(p.val);
                if (p.left != null) Q.add(p.left);
                if (p.right != null) Q.add(p.right);                    
            } // end-for
        } //end-while        

        // Now, reverse the "odd" levels
        for (int i=0; i<result.size(); i++)
            if (i % 2 == 1)
                Collections.reverse(result.get(i));
        
        return result;        
    }
}