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
    void inorder(TreeNode *root, stack<int>&st,int &k)
    {
        if(!root or st.size()>=k)
            return;
        
        inorder(root->left,st,k);
        
        if(st.size()<k)
            st.push(root->val);
        
        inorder(root->right,st,k);
        
    }
    
    int kthSmallest(TreeNode* root, int k) {
        stack<int>v;
        inorder(root,v,k);        
        return v.top();
    }
};