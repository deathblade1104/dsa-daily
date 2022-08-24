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
     int ans;
 
    void helper(TreeNode* root,int &curr)
    {
        curr*=10;
        curr+=root->val;

        if(!root->left and !root->right)
        {
            ans +=curr;
            return;
        }

        if(root->left)
        {
            helper(root->left,curr);
            curr/=10;
        }

        if(root->right)
        {
            helper(root->right,curr);
            curr/=10;
        }
        
        return;
    }
    
    int sumNumbers(TreeNode* root) {
        ans =0;
        int curr =0;
        helper(root,curr);
        return ans;
    }
};