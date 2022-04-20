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
    TreeNode *prev=NULL,*first=NULL,*second=NULL;
    
    void get_ans(TreeNode *root)
    {
        if(!root)
            return;
        
        get_ans(root->left);
        if(prev!=NULL and root->val<prev->val)
        {
            if(!first)
                first=prev;

            second = root;
        }        
        prev= root;
        get_ans(root->right);
        
        return;
    }
    
    void recoverTree(TreeNode* root) {
      
        get_ans(root);
        swap(first->val,second->val);
        
        return;
    }
};