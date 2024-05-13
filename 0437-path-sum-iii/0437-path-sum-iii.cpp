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
    
    
    void get_ans(TreeNode *root, unordered_map<long long,int>&mp, long long&p_sum, long long&k, int &ans)
    {
        if(!root)
            return;
        
        long long curr=root->val*(1LL);
        p_sum+=curr;

        if(p_sum==k)
            ans++;

        if(mp.count(p_sum-k)==1)
            ans+=mp[p_sum-k];

        mp[p_sum]++;
        
        get_ans(root->left,mp,p_sum,k,ans);
        get_ans(root->right,mp,p_sum,k,ans);
        
        if(mp[p_sum]==1)
            mp.erase(p_sum);
        
        else mp[p_sum]--;
        
        p_sum-=root->val;
        
        return;
    }
    int pathSum(TreeNode* root,long long targetSum) {
        
        if(!root)
            return 0;
        int ans=0;
        long long ps=0;
        unordered_map<long long,int>mp;
        get_ans(root,mp,ps,targetSum,ans);
        return ans;
        
    }
};