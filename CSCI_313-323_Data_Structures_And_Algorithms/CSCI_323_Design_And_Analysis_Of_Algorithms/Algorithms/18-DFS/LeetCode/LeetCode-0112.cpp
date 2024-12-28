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
public:
    bool pathSumAux(TreeNode *root, int sum, int pathSum){
        if (root == NULL) return false;

        pathSum += root->val;

        // Do the check when we are at a leaf node
        if (root->left == NULL && root->right == NULL){
            if (pathSum == sum) return true;
            else                return false;
        } //end-if

        if (pathSumAux(root->left, sum, pathSum)) return true;
        return pathSumAux(root->right, sum, pathSum);
    } //end-pathSumAux

    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) return false;

        return pathSumAux(root, sum, 0);
    } //end-hasPathSum
};