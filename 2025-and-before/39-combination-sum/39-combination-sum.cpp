class Solution {
public:
    void helper(int curr, int&target,vector<int>&nums, vector<int>&temp, vector<vector<int>>&ans)
    {
        if(target==0)
        {
            ans.push_back(temp);
            return;
        }
        
        if(curr>=nums.size() or target<nums[curr])
            return;
        
        if(target>=nums[curr])
        {
            temp.push_back(nums[curr]);
            target-=nums[curr];
            helper(curr,target,nums,temp,ans);
            target+=nums[curr];
            temp.pop_back();
        }
        
        helper(curr+1,target,nums,temp,ans);        
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>temp;
        vector<vector<int>>ans;
        
        helper(0,target,candidates,temp,ans);
        return ans;
    }
};