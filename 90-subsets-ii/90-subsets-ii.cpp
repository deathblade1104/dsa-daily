class Solution {
public:
    void helper(int curr,vector<int>&nums, vector<int>&temp, vector<vector<int>>&ans)
    {
        ans.emplace_back(temp);
            
        for(int i=curr;i<nums.size();i++)
        {
            if(i>curr and nums[i]==nums[i-1])
                continue;

            temp.emplace_back(nums[i]);
            helper(i+1,nums,temp,ans);
            temp.pop_back();
        }       
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        
        vector<int>temp;
        vector<vector<int>>ans;
        
        helper(0,nums,temp,ans);
        return ans;
    }
};