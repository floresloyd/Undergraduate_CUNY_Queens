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
    /// Do a level-by-level traversal using a queue
    /// We will push the tree nodes into a queue by attaching a "level" value to
    /// each node. Thus, when we get the node from the queue, we know at which level
    /// this node resides.
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        if (root == NULL) return result;

        // <node, level>
        queue<pair<TreeNode *, int>> Q;
        int currentLevel = 0;
        Q.push(make_pair(root, currentLevel));

        double sum = 0;   // Sum of the elements at this level
        int n = 0;        // # of nodes at this level

        while (!Q.empty()){
            auto [p, level] = Q.front();
            Q.pop();   // Remove from the queue

            // Did we go to the next level?
            if (level > currentLevel){
                result.push_back(sum/n);
                sum = n = 0;
                currentLevel = level;
            } // end-if

            n++;
            sum += p->val;

            if (p->left) Q.push(make_pair(p->left, level+1));
            if (p->right) Q.push(make_pair(p->right, level+1));
        } //end-while

        // Push the average for the last level
        if (n > 0) result.push_back(sum/n);

        return result;
    } // end-averageOfLevels
};