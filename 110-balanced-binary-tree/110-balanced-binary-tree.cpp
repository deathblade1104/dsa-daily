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
    int DFS(TreeNode *root,bool&ans)
    {
        if(!root)
            return 0;
        
        if(root->left==NULL and root->right==NULL)
            return 1;
        
        int d1=DFS(root->left,ans),d2=DFS(root->right,ans);
        
        if(abs(d1-d2)>1)
            ans=false;
        
        return max(d1,d2)+1;
    }
public:
    bool isBalanced(TreeNode* root) {
        bool ans=true;
        int x=DFS(root,ans);
        
        return ans;
    }
};