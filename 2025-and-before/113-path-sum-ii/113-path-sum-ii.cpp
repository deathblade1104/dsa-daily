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
    
    void get_ans(TreeNode *root, int&ts, vector<int>&temp, vector<vector<int>>&ans)
    {
        if(!root)
            return;
        
        ts-=root->val;
        temp.push_back(root->val);        
        
        if(!root->left and !root->right)
        {
            if(ts==0)
                ans.push_back(temp);
        }
        
        
        get_ans(root->left,ts,temp,ans);
        get_ans(root->right,ts,temp,ans);
        
        temp.pop_back();
        ts+=root->val;
        
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<vector<int>>ans;
        vector<int>temp;        
        
        get_ans(root,targetSum,temp,ans);
        return ans;
        
    }
};