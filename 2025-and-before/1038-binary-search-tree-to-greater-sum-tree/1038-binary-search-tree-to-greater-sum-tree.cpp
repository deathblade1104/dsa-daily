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
    void get_inorder(TreeNode *root, vector<int>&inorder)
    {
        if(!root)
            return;
        
        get_inorder(root->left,inorder);
        inorder.push_back(root->val);
        get_inorder(root->right,inorder);
        
        return;
    }
    
    void helper(TreeNode *root,vector<int>&inorder,int&itr)
    {
        if(!root)
            return;
        
        helper(root->left,inorder,itr);
        root->val = inorder[itr++];
        helper(root->right,inorder,itr);
        
        return;
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        vector<int>inorder;
        
        get_inorder(root,inorder);
        
        for(int i=inorder.size()-2;i>=0;i--)
        inorder[i]+=inorder[i+1];
        
        int itr=0;
        helper(root,inorder,itr);
        
        return root;
    }
};