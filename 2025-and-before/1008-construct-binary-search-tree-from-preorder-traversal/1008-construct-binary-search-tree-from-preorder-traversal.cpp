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
    TreeNode *get_ans(vector<int>&preorder, int&pre_itr, int max_val)
    {
        if(pre_itr>=preorder.size() or preorder[pre_itr]>max_val)
            return NULL;
        
        
        TreeNode *root = new TreeNode (preorder[pre_itr++]);
        
        root->left = get_ans(preorder,pre_itr,root->val);
        root->right = get_ans(preorder,pre_itr,max_val);

        return root;
        
        
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int pre_itr=0,max_val=1001;
        return get_ans(preorder,pre_itr,max_val);
        
    }
};