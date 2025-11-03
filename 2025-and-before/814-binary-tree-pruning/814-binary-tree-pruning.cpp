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
    TreeNode *temp;
    pair<TreeNode*,int>helper(TreeNode *root){
        
        pair<TreeNode*,int>ans = make_pair(temp,0);
        
        if(!root)
            return ans;
        
        auto pl = helper(root->left), pr = helper(root->right);
        
        root->left = pl.first;
        root->right = pr.first;
        
        int sum = pl.second + pr.second + root->val;
        
        if(sum<1)
            return ans;
        
        ans.first = root;
        ans.second = sum;
        
        return ans;
        
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        
        temp=NULL;
        auto p = helper(root);
        
        return p.first;
        
        
    }
};