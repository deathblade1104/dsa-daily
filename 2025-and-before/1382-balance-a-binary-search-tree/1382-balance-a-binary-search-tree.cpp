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
    
    void get_inorder(TreeNode *root,vector<int>&inorder)
    {
        if(!root)
            return;
        
        get_inorder(root->left,inorder);
        inorder.push_back(root->val);
        get_inorder(root->right,inorder);
        
        return;
    }
    
    TreeNode* createTree(vector<int>&inorder,int l,int h)
    {
        if(l>h)
            return NULL;
        
        int mid= l + ((h-l)/2);
        TreeNode *root = new TreeNode(inorder[mid]);
        
        root->left = createTree(inorder,l,mid-1);
        root->right = createTree(inorder,mid+1,h);
        
        return root;       
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>inorder;
        get_inorder(root,inorder);
        
        int l=0, h= inorder.size()-1;
        return createTree(inorder,l,h);        
    }
};