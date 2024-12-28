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
    /// This time we will simply do a recursive tree traversal, and pass the level
    /// of the node as a parameter to the function. We will simply find the sum
    /// of all nodes and their count at each level. Finally, we will use
    /// this information to compute the averages
    void dfs(TreeNode *root, int level, vector<pair<double, int>> &levelSums){
        if (root == NULL) return;

        if (level >= levelSums.size()) levelSums.push_back(make_pair(root->val, 1));
        else {
            levelSums[level].first += root->val;    // Increment sum
            levelSums[level].second++;              // Increment # of nodes
        } //end-else

        dfs(root->left, level+1, levelSums);
        dfs(root->right, level+1, levelSums);
    } //end-dfs

    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        if (root == NULL) return result;

        vector<pair<double, int>> levelSums;
        dfs(root, 0, levelSums);

        for (size_t i=0; i<levelSums.size(); i++){
            result.push_back(levelSums[i].first/levelSums[i].second);
        } //end-for

        return result;
    } //end-averageOfLevels
};