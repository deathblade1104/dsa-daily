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
    

    TreeNode* get_left(TreeNode *root)
    {
        if(!root->left)
            return root;
        
        return get_left(root->left);
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(!root)
            return root;
                
        if(root->val>key)
        root->left = deleteNode(root->left,key);          
        
        else if(root->val<key)
        root->right = deleteNode(root->right,key);           
        
        
        else
        {
            if(!root->left and !root->right)
            root=NULL;
        
            else if(root->left and !root->right)
                root= root->left;

            else if(root->right and !root->left)
                root = root->right;

            else
            {
                TreeNode *temp = get_left(root->right);
                swap(root->val,temp->val);

                root->right = deleteNode(root->right,temp->val);

            }
        }
        
        return root;        
        
    }
};