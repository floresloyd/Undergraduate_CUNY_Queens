/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    /// O(n) algorithm with O(d) extra space
    /// -1 indicates that the tree is NOT balanced
    int computeDepth(TreeNode *root){
        if (root == nullptr) return 0;
        int leftDepth = computeDepth(root->left);
        if (leftDepth < 0) return -1;

        int rightDepth = computeDepth(root->right);
        if (rightDepth < 0) return -1;

        if (std::abs(leftDepth-rightDepth) > 1) return -1;
        return 1 + std::max(leftDepth, rightDepth);
    }
public:
    bool isBalanced(TreeNode* root) {
        return computeDepth(root) >= 0;
    }
};