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
    int get_ans(TreeNode *root)
    {
        if(!root)
            return 100001;
        
        if(!root->left and !root->right)
            return 1;
        
        int l = get_ans(root->left);
        int r = get_ans(root->right);
        
        return 1 + min(l,r);
    }
    
    int minDepth(TreeNode* root) {
        int ans =  get_ans(root);
        
        if(ans>=100001)
            return 0;
        
        return ans;
    }
};