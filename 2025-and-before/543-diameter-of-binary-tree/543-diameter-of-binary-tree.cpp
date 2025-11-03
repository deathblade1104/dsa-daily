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
    int get_ans(TreeNode* root,int&ans)
    {
        if(!root)
            return 0;
        
        int l = get_ans(root->left,ans);
        int r = get_ans(root->right,ans);
        
        ans= max(ans,l+r);
        return max(l,r)+1;
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;

        int x = get_ans(root,ans);
        return ans;
    }
};