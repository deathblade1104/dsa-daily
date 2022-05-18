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
    bool DFS(TreeNode *root, unordered_set<int>&st, int target)
    {
        if(!root)
            return false;
        
        if(DFS(root->left,st,target))
            return true;
        
        if(st.count(target - root->val)==1)
            return true;
        
        st.insert(root->val);
        
        return DFS(root->right,st,target);
    }
    
    bool findTarget(TreeNode* root, int k) {
        
        unordered_set<int>st;
        
        return DFS(root,st,k);
    }
};