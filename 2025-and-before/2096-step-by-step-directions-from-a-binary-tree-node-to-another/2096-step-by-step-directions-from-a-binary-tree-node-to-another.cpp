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
   
    TreeNode *lca(TreeNode *root, int sv, int dv)
    {
        if(!root)
            return NULL;
        
        if(root->val==sv or root->val==dv)
            return root;
        
        TreeNode *l= lca(root->left,sv,dv);
        TreeNode *r= lca(root->right,sv,dv);
        
        if(l and r)
            return root;
        else if(!r)
            return l;
        else return r;
        
    }    
    
    
    bool solve(TreeNode* root,int tar,string &res)
    {
        if(root == NULL)
        return false;
        
        if(root->val == tar)
        return true;
        
        res.push_back('L');
        if(solve(root->left,tar,res))
        return true;
        
        res.pop_back();
        
        res.push_back('R');
        if(solve(root->right,tar,res))
        return true;
        
        res.pop_back();
        
        return false;
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        
        TreeNode *source=lca(root,startValue,destValue);
        string ans1="",ans2="";
        
        solve(source,startValue,ans1);
        solve(source,destValue,ans2);
        
        for(int i=0;i<ans1.size();i++)
            ans1[i]='U';      
        
        return   ans1+ans2;
        
        
    }
};