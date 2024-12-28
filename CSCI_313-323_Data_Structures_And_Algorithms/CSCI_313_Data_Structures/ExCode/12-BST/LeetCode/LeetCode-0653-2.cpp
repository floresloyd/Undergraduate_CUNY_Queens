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
class BSTForwardIterator {
    stack<TreeNode *> S;
public:
    BSTForwardIterator(TreeNode *root){
        while (root != NULL){S.push(root); root = root->left;}
    }
    bool hasNext(){return not S.empty();}
    int next(){
        TreeNode *p = S.top();
        int ret = p->val;
        S.pop();
        if (p->right != NULL){
            p = p->right;
            while (p != NULL){S.push(p); p=p->left;}
        } //end-if 
        return ret;       
    } // end-next
};

class BSTReverseIterator {
    stack<TreeNode *> S;
public:
    BSTReverseIterator(TreeNode *root){
        while (root != NULL){S.push(root); root = root->right;}
    }
    bool hasNext(){return not S.empty();}
    int next(){
        TreeNode *p = S.top();
        int ret = p->val;
        S.pop();
        if (p->left != NULL){
            p = p->left;
            while (p != NULL){S.push(p); p=p->right;}
        } //end-if 
        return ret;       
    } // end-next
};

class Solution {
public:
    /// Here is an O(n) time algorithm that uses O(logn) extra space
    /// The idea is to create one iterator that walks in
    /// the forward direction (in ascending order of the keys)
    /// and one iterator that walks in the backward direction (in descending order of the keys)
    bool findTarget(TreeNode* root, int k) {
        BSTForwardIterator forwardIter(root);
        BSTReverseIterator reverseIter(root);

        int num1 = forwardIter.next();
        int num2 = reverseIter.next();

        while (num1 < num2){
            int sum = num1 + num2;

            if (sum == k) return true; // Found it
            if (sum < k) num1 = forwardIter.next();
            else num2 = reverseIter.next();
        } //end-while

        return false;
    } //end-findTarget
};