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
       
       for(int i=1;i<=9;i++)
       {
           if(mp[i]&1) odd++;
           
           if(odd>1)
               return false;
       }
       
       return true;
   }

   void dfs(TreeNode *root, int &ans, vector<int>&mp)
    {
        if(!root)
            return;
        
        mp[root->val]++;
        
        if(!root->left and !root->right)
        {
            if(check(mp))
                ans++;
        }
        
        dfs(root->left,ans,mp);
        dfs(root->right,ans,mp);        
        
        mp[root->val]--;
        return;
        
        
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int>mp(10,0);
        int ans=0;
        
        dfs(root,ans,mp);
        
        return ans;
        
    }
};