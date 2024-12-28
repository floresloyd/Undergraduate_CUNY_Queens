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
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        if (root == NULL) return result;
        
        queue<TreeNode *> Q;
        Q.push(root);
                    
        while (!Q.empty()){
            int n = Q.size();  // # of nodes at this level
            
            // Add a new list to the end of the result
            int maxVal = INT_MIN;
            for (int i=0; i<n; i++){
                auto p = Q.front();
                Q.pop();
                maxVal = std::max(maxVal, p->val);
                if (p->left) Q.push(p->left);
                if (p->right) Q.push(p->right);                    
            } // end-for
            result.push_back(maxVal);
        } //end-while        

        return result;        
    } // end-largestValues
};