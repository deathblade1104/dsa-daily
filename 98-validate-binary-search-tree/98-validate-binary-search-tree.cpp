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
    TreeNode* prev;
    void get_ans(TreeNode *root, bool &ans)
    {
        if(!root or !ans)
            return;
        
        get_ans(root->left,ans);
        
        if(prev!=NULL and root->val<=prev->val)
        {
            // cout<<root->val<<endl;
            ans = false;
        } 
        
        prev= root;
        get_ans(root->right,ans);
    }
    
    bool isValidBST(TreeNode* root){
        prev= NULL;
        bool ans = true;
        get_ans(root,ans);
        
        return ans;
    }
};