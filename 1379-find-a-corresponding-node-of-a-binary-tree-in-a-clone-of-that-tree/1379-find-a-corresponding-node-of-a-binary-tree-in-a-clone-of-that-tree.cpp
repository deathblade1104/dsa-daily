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
   
    TreeNode* getTargetCopy(TreeNode* root, TreeNode* cloned, TreeNode* target)   {
        if(root==NULL) return NULL;
        
        
        if(root==target)
            return cloned;
        
        TreeNode *l= getTargetCopy(root->left,cloned->left,target);
        TreeNode *r= getTargetCopy(root->right,cloned->right,target);
        
        if(l)
            return l;
        
        else if (r)
            return r;
        
        return NULL;
    }
};