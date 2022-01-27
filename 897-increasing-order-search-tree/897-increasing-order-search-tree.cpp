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
    void inorder(TreeNode *root, vector<int>&v)
    {
        if(!root)
            return;
        
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
        
    }
        
    TreeNode* increasingBST(TreeNode* root) {
        
        vector<int>v;
        inorder(root,v);
        
        TreeNode *dummy = new TreeNode(-1);
        TreeNode *curr=dummy;
        for(int i=0;i<v.size();i++)
        {
            TreeNode* temp= new TreeNode(v[i]);
            curr->right=temp;
            curr=curr->right;
        }
        
        return dummy->right;
    }
};