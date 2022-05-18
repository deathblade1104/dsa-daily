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
    int get_max(vector<int>&nums, int l,int h)
    {
        int ans = l;
        
        for(int i=l+1;i<=h;i++)
        {
            if(nums[i]>nums[ans])
                ans = i;
        }
        
        return ans;
    }
    
    TreeNode *createTree(vector<int>&nums ,int l ,int h)
    {
        if(l>h)
            return NULL;        
        
        int idx = get_max(nums,l,h);
        
        TreeNode *root = new TreeNode(nums[idx]);
        
        root->left = createTree(nums,l,idx-1);
        root->right = createTree(nums,idx+1,h);
        
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int l=0, h = nums.size()-1;
        return createTree(nums,l,h);
    }
};