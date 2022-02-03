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
    bool get_ans(TreeNode *root,  int sum, int target)
    {
        if(!root)
            return false;
        
        if(!root->left and !root->right)
        {
            if(target==(sum + root->val))
                return true;
            
            return false;
        }
        
        return get_ans(root->left,sum+root->val,target) 
            or get_ans(root->right,sum+root->val,target);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return get_ans(root,0,targetSum);
    }
};