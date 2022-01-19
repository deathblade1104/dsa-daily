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
    
    void get_ans(TreeNode *root)
    {
        if(root==NULL) return;
        
        TreeNode *temp=root->left;
        root->left=root->right;
        root->right=temp;
        
        get_ans(root->left);
        get_ans(root->right);
        
        return;
    }
    TreeNode* invertTree(TreeNode* root) {
        get_ans(root);
        
        return root;           
    }
};