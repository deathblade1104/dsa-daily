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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        
        if(!root)
            return NULL;
        
        if(root->val < low)
            return  trimBST(root->right,low,high);
        
        else if (root->val > high)
            return trimBST(root->left,low,high);
        

        TreeNode *l=trimBST(root->left,low,high);
        TreeNode *r=trimBST(root->right,low,high);

        root->left = l;
        root->right = r;

        return root;        
    }
};