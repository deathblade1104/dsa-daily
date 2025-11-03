class Solution {
public:
void helper(int curr, int&target,vector<int>&nums, vector<int>&temp, vector<vector<int>>&ans)
    {
        if(target==0)
        {
            ans.push_back(temp);
            return;
        }
                
        for(int i=curr;i<nums.size();i++)
        {
            if(target<nums[i])
                break;
            
            if(i>curr and nums[i]==nums[i-1])
                continue;
            
            temp.push_back(nums[i]);
            target-=nums[i];
            helper(i+1,target,nums,temp,ans);
            target+=nums[i];
            temp.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>temp;
        vector<vector<int>>ans;
        
        helper(0,target,candidates,temp,ans);
        return ans;
    }
};