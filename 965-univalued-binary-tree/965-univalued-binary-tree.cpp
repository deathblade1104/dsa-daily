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
    bool get_ans(TreeNode *root , int v)
    {
        if(root==NULL) return true;
        
        return ((root->val == v) && get_ans(root->left,v) && get_ans(root->right,v));
    }
    bool isUnivalTree(TreeNode* root) {
        if(root==NULL) return true;
        
        int v=root->val;
        
        return get_ans(root,v);
    }
};