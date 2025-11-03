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
    bool get_ans(TreeNode *root, int ts)
    {
        if(!root->left and !root->right)
            return (root->val == ts);
        
        bool l = false, r = false;
        
        if(root->left)
            l = get_ans(root->left, ts - root->val);
        
        if(root->right)
            r = get_ans(root->right, ts - root->val);
        
        return l | r;   
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        if(!root)
            return false;
        
        return get_ans(root,targetSum);
    }
};