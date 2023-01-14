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
    
    void DFS(TreeNode *root,int par,int gp){
        
        if(!root)
            return;
        
        if(gp%2==0)
            ans+=root->val;
        
        DFS(root->left,root->val,par);
        DFS(root->right,root->val,par);
        
        return;
    }
    int sumEvenGrandparent(TreeNode* root) {
        ans=0;
        
        DFS(root,-1,1);
        
        return ans;

    }
};