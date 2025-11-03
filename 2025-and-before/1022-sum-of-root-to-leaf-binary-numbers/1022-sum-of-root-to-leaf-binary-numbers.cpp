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
    void get_ans(TreeNode *root, int n, int &ans)
    {
        if(root==NULL) return;
        
        if(root->left==NULL and root->right==NULL)
        {   
            int num=n;
            if(root->val==0)
                num*=2;
            
            else
                num=(num*2)+1;
            
            ans+= num;
            return;
        }
        
        
        int num;
        if(root->val==0)
            num=n*2;
        
        else
            num=(n*2)+1;
        
        
        get_ans(root->left,num,ans);
        get_ans(root->right,num,ans);
        
        return;        
    }
    
    int sumRootToLeaf(TreeNode* root) {
        
        int ans=0;
        get_ans(root,0,ans);
        return ans;
        
    }
};