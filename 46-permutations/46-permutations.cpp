class Solution {
public:
    void helper(int curr, int&sz, vector<int>&nums, vector<vector<int>>&ans)
    {
        if(curr>=sz)
        {
            ans.push_back(nums);
            return;
        }
        
        for(int i=curr;i<sz;i++)
        {
            swap(nums[i],nums[curr]);
            helper(curr+1,sz,nums,ans);
            swap(nums[i],nums[curr]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        int sz=nums.size();
        
        helper(0,sz,nums,ans);
        return ans;
    }
};