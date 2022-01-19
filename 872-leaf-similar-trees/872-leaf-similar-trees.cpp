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
    void get_leaves(TreeNode *root,vector<int>&v)
    {
        if(root==NULL)
            return;
        
        if(root->left==NULL and root->right==NULL)
        {
            v.push_back(root->val);
            return;
        }
        
        get_leaves(root->left,v);
        get_leaves(root->right,v);
        
        return;
     }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>t1,t2;
        
        get_leaves(root1,t1);        
        get_leaves(root2,t2);
        
        if(t1.size()!=t2.size())
            return false;
        
        else
        {
            int i=0;
            while(i<t1.size())
            {
                if(t1[i]!=t2[i])
                    return false;
                
                i++;
            }
            
            return true;
        }
    }
};