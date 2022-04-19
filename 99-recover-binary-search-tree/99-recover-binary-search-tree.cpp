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
    void get_tree(TreeNode *root, vector<int>&v)
    {
        if(!root)
            return;
        
        get_tree(root->left,v);
        v.push_back(root->val);
        get_tree(root->right,v);
        return;
    }
    void buildBST(TreeNode *root, int&i,vector<int>&v)
    {
        if(!root or i>=v.size())
            return;
        
        buildBST(root->left,i,v);
        
        if(i<v.size())
            root->val=v[i++];
        
        buildBST(root->right,i,v);
        return;
    }
    void recoverTree(TreeNode* root) {
        
        vector<int>v;
        get_tree(root,v);
        sort(v.begin(),v.end());
        int i=0;
        buildBST(root,i,v);
        return;
    }
};