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
        if(!root)
            return ;
        
        get_ans(root->left);
        get_ans(root->right);
        
        TreeNode *temp = root->left;
        root->left=root->right;
        root->right = temp;
    }
    TreeNode* invertTree(TreeNode* root) {
        get_ans(root);
        return root;
        
    }
};