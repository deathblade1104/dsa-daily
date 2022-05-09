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

    
    TreeNode *get_ans(vector<int>&preorder, int&pre_itr, unordered_map<int,int>&mp, int l, int r)
    {       
        TreeNode *root= new TreeNode(preorder[pre_itr]);
        
        int idx = mp[preorder[pre_itr++]];
        
        if(l<=idx-1)        
        root->left = get_ans(preorder,pre_itr,mp,l,idx-1);
        
        if(idx+1<=r)
        root->right = get_ans(preorder,pre_itr,mp,idx+1,r);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int pre_itr=0,l=0,r=inorder.size()-1;
        
        unordered_map<int,int>mp;
        for(int i=l;i<=r;i++)
            mp[inorder[i]]=i;
                    
        return get_ans(preorder,pre_itr,mp,l,r);
        
    }
};