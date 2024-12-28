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
    /// Consider the state of the Q at the end of an iteration
    /// Assume we just finished processing a level
    /// What is the current content of the Q? All nodes at the next level
    /// So, we will simply have a for loop to process the nodes at the next level!
    ///
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        if (root == NULL) return result;

        queue<TreeNode *> Q;
        Q.push(root);
        
        while (!Q.empty()){
            int n = Q.size();  // # of nodes at this level
            double sum = 0;    // Sum of the node values at this level
            
            for (int i=0; i<n; i++){
                auto p = Q.front();
                Q.pop();
                sum += p->val;
                if (p->left) Q.push(p->left);
                if (p->right) Q.push(p->right);                    
            } // end-for

            result.push_back(sum/n);
        } //end-while

        return result;
    } // end-averageOfLevels
};