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
    
    void DFS(TreeNode *root, int prev1, int prev2,int&ans,bool flag)
    {
        if(!root)
            return;
        
        if(!flag)
            ans = max({ans,abs(prev1 - root->val),abs(prev2 - root->val)});
        
        DFS(root->left,min(root->val,prev1),max(root->val,prev2),ans,false);
        DFS(root->right,min(root->val,prev1),max(root->val,prev2),ans,false);
        
    }
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0,prev1  = INT_MAX, prev2 = INT_MIN;                                       
        DFS(root,prev1,prev2,ans,true);
        
        return ans;
        
    }
};