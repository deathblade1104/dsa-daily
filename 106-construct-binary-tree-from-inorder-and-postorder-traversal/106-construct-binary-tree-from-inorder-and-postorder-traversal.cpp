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
       
    TreeNode *get_ans(vector<int>&postorder, int&post_itr, unordered_map<int,int>&mp, int l, int r)
    {       
        TreeNode *root= new TreeNode(postorder[post_itr]);
        
        int idx = mp[postorder[post_itr--]];
        
        if(idx+1<=r)
        root->right = get_ans(postorder,post_itr,mp,idx+1,r);
        
        if(l<=idx-1)        
        root->left = get_ans(postorder,post_itr,mp,l,idx-1);        
                
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int post_itr=postorder.size()-1,l=0,r=inorder.size()-1;
        
        unordered_map<int,int>mp;
        for(int i=l;i<=r;i++)
            mp[inorder[i]]=i;
                    
        return get_ans(postorder,post_itr,mp,l,r);
        
    }
};