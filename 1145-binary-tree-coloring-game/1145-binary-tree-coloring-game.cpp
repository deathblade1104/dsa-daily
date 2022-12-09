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
    
    TreeNode* getPar(TreeNode *root,int x){
        if(!root)
            return NULL;
        
        if(root->left!=NULL and root->left->val == x)
            return root;
        
        if(root->right!=NULL and root->right->val == x)
            return root;
        
        TreeNode *l = getPar(root->left,x);
        
        if(l!=NULL)
            return l;
        
        TreeNode *r = getPar(root->right,x);
        
        if(r!=NULL)
            return r;
        
        return NULL;
        
    }
    
    int countNodes(TreeNode *root){
        
        if(!root)
            return 0;
        
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
    
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        
        TreeNode *par = (root->val == x) ? NULL : getPar(root,x);
        TreeNode *XNode = (root->val == x) ? root : NULL;
        
        if(par){
            if(par->left and par->left->val ==x)
                XNode= par->left,par->left = NULL;
            
            else 
                XNode = par->right,par->right = NULL; 
        }
        
        int op2 = countNodes(XNode->left), op3 = countNodes(XNode->right),rem = n - 1 - op2 - op3;
        
        if(rem > 1 + op2 + op3)
            return true;
        
        if(op2 > rem + 1 + op3)
            return true;
        
        if(op3 > rem + 1 + op2)
            return true;
        
        return false;
        
    }
};