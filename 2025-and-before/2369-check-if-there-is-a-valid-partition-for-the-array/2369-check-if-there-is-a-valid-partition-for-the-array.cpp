class Solution {
public:
    int dp[100001];
    bool get_ans(int curr,vector<int>&nums)
    {
        if(curr>=nums.size())
            return true;
        
        if(dp[curr]!=-1)
            return dp[curr];
        
        if(curr+1<nums.size())
        {
            if(nums[curr+1] == nums[curr] and get_ans(curr+2,nums))
                return dp[curr] = true;
            
            if(curr+2<nums.size())
            {
                if(nums[curr+2]==nums[curr+1] and nums[curr+1]==nums[curr] and get_ans(curr+3,nums))
                return dp[curr] = true; 
                   
                if(nums[curr+2]==nums[curr+1]+1 and nums[curr+1]==nums[curr]+1 and get_ans(curr+3,nums))
                   return dp[curr] = true;
            }   
        }
        
        return dp[curr] = false;        
        
    }
    
    
    bool validPartition(vector<int>& nums) {
        
        memset(dp,-1, sizeof(dp));
        return get_ans(0,nums);
        
    }
};