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
    TreeNode *get_ans(TreeNode *r1, TreeNode *r2)
    {
        if(!r1 and !r2)
            return NULL;
        
        else if(!r1)
            return r2;
        
        else if(!r2)
            return r1;
         
        TreeNode *temp = new TreeNode(r1->val + r2->val);
        temp->left = get_ans(r1->left, r2->left);
        temp->right = get_ans(r1->right, r2->right);
            
        return temp;
        
        
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return get_ans(root1,root2);
        
    }
};