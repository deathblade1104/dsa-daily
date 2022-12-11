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
    
    int DFS(TreeNode *root,int&ans){
        if(!root)
            return 0;
        
        int l = DFS(root->left,ans), r = DFS(root->right,ans), curr = root->val + l + r;
        
        ans = max(ans,curr);
        
        return max(root->val+max({l,r,0}),0);
    }
    
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        int temp = DFS(root,ans);
        
        return ans;
    }
};