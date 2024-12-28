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
    /// Here is an O(n) time algorithm that uses O(n) extra space
    /// Simply do an in-order traversal and get the keys in sorted order
    /// Then simply do a walk over the sorted array using two pointers,
    /// one starting from the front, and the other starting from the end
    void getSorted(TreeNode *root, vector<int> &nums){
        if (root == NULL) return;
        getSorted(root->left, nums);
        nums.push_back(root->val);
        getSorted(root->right, nums);
    } //end-getSorted

public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> nums;

        getSorted(root, nums);
        if (nums.size() < 2) return false;

        int i=0, j=nums.size()-1;
        while (i<j){
            int sum = nums[i]+nums[j];
            if (sum == k) return true;
            if (sum < k) i++;
            else         j--;
        } //end-while

        return false;
    } //end-findTarget
};