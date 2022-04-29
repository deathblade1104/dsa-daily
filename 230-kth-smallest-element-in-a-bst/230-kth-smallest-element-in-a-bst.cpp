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
    void get_ans(TreeNode *root, vector<int>&v)
    {
        if(!root)
            return;
        
        get_ans(root->left,v);
        
        v.push_back(root->val);
        
        get_ans(root->right,v);
        
    }
    int kthSmallest(TreeNode* root, int k) {
        
        vector<int>v;
        get_ans(root,v);
        return v[k-1];
        
    }
};