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
    void get_ans(TreeNode *root, int max_encountered, int &ans)
    {
        if(!root)
            return;
        
        if(root->val>=max_encountered)
            ans++;
        
        get_ans(root->left, max(root->val,max_encountered),ans);
        get_ans(root->right, max(root->val,max_encountered),ans);
    }
    
    int goodNodes(TreeNode* root) {
        int  ans=0, start = -100001;
        get_ans(root, start,ans);
        return ans;
    }
};