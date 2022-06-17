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
    int helper(TreeNode *root,int&res)
    {
        if(!root)
            return 1;
        
        if(!root->left and !root->right)
            return -1;
        
        int lc = helper(root->left,res), rc= helper (root->right,res);
        
        if(lc==-1 or rc==-1)
        {
            res++;
            return 0;
        }
        
        if(lc==0  or  rc==0)
            return 1;
        
        return -1;
        
            
    }
    
    int minCameraCover(TreeNode* root) {
         int ans , res =0;
        ans = helper(root,res);
        
        if(ans==-1)
            res++;
        
        return res;
    }
};