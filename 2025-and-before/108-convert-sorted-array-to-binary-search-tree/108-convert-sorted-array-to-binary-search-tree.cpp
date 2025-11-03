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
    TreeNode* get_ans(vector<int>&nums, int start, int end)
    {
        if(start>end)
            return NULL;
        
        int mid = (start+end)/2; 
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = get_ans(nums,start,mid-1);
        root->right = get_ans(nums,mid+1,end);
        
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int start = 0 , end = nums.size()-1;
        return get_ans(nums,start,end);
    }
};