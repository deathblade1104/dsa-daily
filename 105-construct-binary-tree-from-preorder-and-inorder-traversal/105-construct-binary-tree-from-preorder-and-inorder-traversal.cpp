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
    
    int get_inorder_index(vector<int>&inorder,int l, int r, int&target)
    {
        for(int i=l;i<=r;i++)
        {
            if(inorder[i]==target)
                return i;
        }
        
        return -1;
    }
    
    TreeNode *get_ans(vector<int>&preorder, int&pre_itr, vector<int>&inorder, int l, int r)
    {
        
        if(l>r)
            return NULL;
        
        TreeNode *root= new TreeNode(preorder[pre_itr]);
        
        int idx = get_inorder_index(inorder,l,r,preorder[pre_itr]);
        pre_itr++;
        
        root->left = get_ans(preorder,pre_itr,inorder,l,idx-1);
        root->right = get_ans(preorder,pre_itr,inorder,idx+1,r);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int pre_itr=0,l=0,r=inorder.size()-1;
        
        return get_ans(preorder,pre_itr,inorder,l,r);
        
    }
};