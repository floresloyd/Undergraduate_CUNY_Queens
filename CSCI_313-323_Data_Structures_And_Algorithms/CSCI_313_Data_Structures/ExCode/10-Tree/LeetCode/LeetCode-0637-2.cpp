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
    ///------------------------------------------------------------
    /// Do a level-by-level traversal using a queue
    /// Do not attach "level" to each node in the queue
    /// But how do we determine the end of a level? The idea is to push
    /// a NULL pointer to the queue to mark the end of a level
    ///
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        if (root == NULL) return result;

        queue<TreeNode *> Q;
        Q.push(root);
        Q.push(NULL);     // This marks the end of the nodes at this level

        double sum = 0;   // Sum of the elements at this level
        int n = 0;        // # of nodes at this level

        while (!Q.empty()){
            TreeNode *p = Q.front();
            Q.pop();

            // Have we reached the end of a level?
            if (p == NULL){
                result.push_back(sum/n);
                sum = n = 0;
                if (!Q.empty()) Q.push(NULL);  // Mark the end of the next level

            } else {
                n++;
                sum += p->val;
                if (p->left) Q.push(p->left);
                if (p->right) Q.push(p->right);
            } //end-else
        } //end-while

        return result;
    } // end-averageOfLevels
};