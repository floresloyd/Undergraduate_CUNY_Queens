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
    bool validate(TreeNode *root, int64_t leftVal, int64_t rightVal){
        if (root == nullptr) return true;
        if (root->val < leftVal || root->val > rightVal) return false;
        if (!validate(root->left, leftVal, root->val-1L)) return false;
        return validate(root->right, root->val+1L, rightVal);
    } // end-validate

public:
    bool isValidBST(TreeNode* root) {
        return validate(root, INT64_MIN, INT64_MAX);
    }
};