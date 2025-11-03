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
    
   bool check(vector<int>&mp)
   {
       int odd=0;
       
       for(int i=0;i<9;i++)
       {
           if(mp[i]&1) odd++;
           
           if(odd>1)
               return false;
       }
       
       return true;
   }

   void dfs(TreeNode *root, int &ans, vector<int>&mp)
    {       
        mp[root->val-1]++;
        
        if(!root->left and !root->right and check(mp))
                ans++;
        
       if(root->left)
        dfs(root->left,ans,mp);
       
       if(root->right)
        dfs(root->right,ans,mp);        
        
        mp[root->val-1]--;
        return;
        
        
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int>mp(9,0);
        int ans=0;
        
        dfs(root,ans,mp);
        
        return ans;
        
    }
};