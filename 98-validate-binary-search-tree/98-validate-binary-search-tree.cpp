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
    
    bool first = true;
    bool DFS(TreeNode *root, int&check)
    {
        if(!root)
            return true;
        
        bool op1 = DFS(root->left,check);
        
        if(root->val<=check and !first or !op1)
            return false;
        
        first = false;        
        check = root->val;        
        bool op2 = DFS(root->right,check);
        
        return op1&op2;
    }
    bool isValidBST(TreeNode* root) {
        
        int check = INT_MIN;
        return DFS(root,check);
        
    }
};