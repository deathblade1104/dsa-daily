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
    
    
    void getLevelAndGrandParent(TreeNode *root,int par,int&lvl,int&val,pair<int,int>&ans){
        
        if(!root)
            return;
        
        if(root->val == val){
            ans.first = par;
            ans.second = lvl;
            
            return;
        }
        lvl++;
        
        getLevelAndGrandParent(root->left,root->val,lvl,val,ans);
        getLevelAndGrandParent(root->right,root->val,lvl,val,ans);
        
        lvl --;
        
        return;
    }
    bool isCousins(TreeNode* root, int x, int y) {
        
        
        pair<int,int>p1,p2;
        int lvl = 1;
        getLevelAndGrandParent(root,-1,lvl,x,p1);
        getLevelAndGrandParent(root,-2,lvl,y,p2);
        
        
        if(p1.first != p2.first and p1.second == p2.second)
            return true;
        
        
        return false;
    }
};