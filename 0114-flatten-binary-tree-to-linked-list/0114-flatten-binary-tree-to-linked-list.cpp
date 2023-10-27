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
    TreeNode *helper(TreeNode *root){
        
        if(root == nullptr)
            return root;
        
     TreeNode *left = root->left;
    TreeNode *right = root->right;

    root->left = nullptr; // Set left child to null

    root->right = helper(left); // Connect the right child to the rightmost node in the left subtree
    TreeNode *temp = root;
    
    while (temp->right != nullptr) {
        temp = temp->right;
    }
    
    temp->right = helper(right); 
        
        return root;
    }
    
    void flatten(TreeNode* root) {
        
        helper(root);
        return;
    }
};