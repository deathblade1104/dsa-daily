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
    int DFS(TreeNode *root){
        if(!root)
            return 0;
        
        int l = DFS(root->left), r = DFS(root->right);
        
        if(root->left and root->left->val!=root->val)
            l=0;
         if(root->right and root->right->val!=root->val)
            r=0;
        
        ans = max(ans,l+r+1);
        //cout<<root->val<<" : "<<ans<<endl;
        return max(l,r) + 1;
    }
    int longestUnivaluePath(TreeNode* root) {
        
        ans = 0;
        if(!root)
            return 0;
        int temp = DFS(root);
        return ans-1;
        
        
    }
};