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
class BSTForwardIterator implements Iterator<Integer> {
    private Stack<TreeNode> S = new Stack<>();
    public BSTForwardIterator(TreeNode root){
        while (root != null){S.push(root); root = root.left;}
    }
    @Override
    public boolean hasNext(){return !S.isEmpty();}

    @Override
    public Integer next(){
        TreeNode p = S.pop();
        int ret = p.val;
        if (p.right != null){
            p = p.right;
            while (p != null){S.push(p); p=p.left;}
        } //end-if 
        return ret;       
    } // end-next
};

class BSTReverseIterator implements Iterator<Integer> {
    private Stack<TreeNode> S = new Stack<>();
    public BSTReverseIterator(TreeNode root){
        while (root != null){S.push(root); root = root.right;}
    }
    @Override
    public boolean hasNext(){return !S.isEmpty();}

    @Override
    public Integer next(){
        TreeNode p = S.pop();
        int ret = p.val;
        if (p.left != null){
            p = p.left;
            while (p != null){S.push(p); p=p.right;}
        } //end-if 
        return ret;       
    } // end-next
};

class Solution {
    /// Here is an O(n) time algorithm that uses O(logn) extra space
    /// The idea is to create one iterator that walks in
    /// the forward direction (in ascending order of the keys)
    /// and one iterator that walks in the backward direction (in descending order of the keys)
    public boolean findTarget(TreeNode root, int k) {
        BSTForwardIterator forwardIter = new BSTForwardIterator(root);
        BSTReverseIterator reverseIter = new BSTReverseIterator(root);

        int num1 = forwardIter.next();
        int num2 = reverseIter.next();

        while (num1 < num2){
            int sum = num1 + num2;

            if (sum == k) return true; // Found it
            if (sum < k) num1 = forwardIter.next();
            else num2 = reverseIter.next();
        } //end-while

        return false;
    }
}