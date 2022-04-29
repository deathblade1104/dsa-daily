/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode *get_ans(TreeNode *root, TreeNode *p, TreeNode*q)
    {
            
        if(root->val>p->val and root->val>q->val)
        return get_ans(root->left,p,q);
        
        else if(root->val<p->val and root->val<q->val)
        return get_ans(root->right,p,q);
        
        return root;
        
        
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *ans= get_ans(root, p, q);
        return ans;
    }
};