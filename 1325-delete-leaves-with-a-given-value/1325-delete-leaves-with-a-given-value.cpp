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
      
    TreeNode *Postorder(TreeNode *root, int target)
    {        
        if(!root)
            return NULL;
        
        root->left = Postorder(root->left,target);
        root->right = Postorder(root->right,target);
        
        if(root->left == NULL and root->right == NULL and root->val == target)
            return NULL;
        
        return root;
    }
    
    
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return Postorder(root,target);
    }
};