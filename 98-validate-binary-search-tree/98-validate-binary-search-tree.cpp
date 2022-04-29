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
    bool first=true;
    bool get_ans(TreeNode *root, int&prev)
    {
        if(!root)
            return true;        
        
        bool op1 = get_ans(root->left,prev);
        
        if(root->val<=prev and !first)
            return false;
        first= false;
        
        prev = root->val;

        bool op2 = get_ans(root->right,prev);
        
        return op1 && op2;
    }
    
    bool isValidBST(TreeNode* root) {
               
        int prev = INT_MIN;
        return get_ans(root,prev);
    }
};