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
    
    int get_ans(TreeNode *root, int&ans)
    {
        if(root==NULL)
            return 0;
        
        int l ,r;
        
        l = get_ans(root->left,ans);
        
        r = get_ans(root->right,ans);
        
        l=max(l,0);
        r=max(r,0);
        
        ans= max(ans,(root->val+l+r));
        
        return max(l,r) + root->val;
    }
    
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        
        int x = get_ans(root,ans);
        
        return ans;
        
    }
};