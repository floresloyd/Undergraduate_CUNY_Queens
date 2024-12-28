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
    vector<vector<int>> levelOrder(TreeNode* root) {        
        vector<vector<int>> result;
        if (root == NULL) return result;
        
        queue<TreeNode *> Q;
        Q.push(root);
                    
        while (!Q.empty()){
            int n = Q.size();  // # of nodes at this level
            
            // Add a new list to the end of the result
            result.push_back({});
            int index = result.size()-1;
            
            for (int i=0; i<n; i++){
                auto p = Q.front();
                Q.pop();
                result[index].push_back(p->val);
                if (p->left) Q.push(p->left);
                if (p->right) Q.push(p->right);                    
            } // end-for
        } //end-while        

        return result;
    } // end-levelOrder
};