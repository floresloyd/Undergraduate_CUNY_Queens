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
    void binaryTreePaths(TreeNode *root, vector<int> &path, vector<string> &paths){
        if (root == NULL) return;

        // Have we reached a leaf node? Then this is the end of a path
        if (root->left == NULL && root->right == NULL){
            string str = "";

            for (int i=0; i<path.size(); i++){
                str.append(to_string(path[i]));
                str.append("->");
            } //end-for

            str.append(to_string(root->val));
            paths.push_back(str);
            return;
        } //end-if

        // Push this node to the path
        path.push_back(root->val);

        binaryTreePaths(root->left, path, paths);  // Traverse the LST
        binaryTreePaths(root->right, path, paths); // Traverse the RST

        // Pop this node back from the path when we are going back up the tree
        path.pop_back();
    } //end-binaryTreePaths

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> path;
        vector<string> paths;

        binaryTreePaths(root, path, paths);

        return paths;
    } // end-binaryTreePaths
};