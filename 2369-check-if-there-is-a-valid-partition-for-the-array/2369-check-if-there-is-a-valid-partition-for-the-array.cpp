class Solution {
public:
    int dp[100001];
    bool get_ans(int curr,vector<int>&nums)
    {
        if(curr==nums.size())
            return true;
        
        if(curr>nums.size())
            return false;
        
        if(dp[curr]!=-1)
            return dp[curr];
        
        bool op1,op2,op3;
        op1 = op2 = op3 = false;
        
        if(curr+1<nums.size())
        {
            if(nums[curr+1] == nums[curr])
                op1 = get_ans(curr+2,nums);
            
            if(op1)
                return dp[curr] = true;
            
            if(curr+2<nums.size())
            {
                if(nums[curr+2]==nums[curr+1] and nums[curr+1]==nums[curr])
                    op2 = get_ans(curr+3,nums);
                
                if(nums[curr+2]==nums[curr+1]+1 and nums[curr+1]==nums[curr]+1)
                    op3 = get_ans(curr+3,nums);
            }
        }
        
        return dp[curr] = op1 || op2|| op3;
        
        
    }
    
    
    bool validPartition(vector<int>& nums) {
        
        memset(dp,-1, sizeof(dp));
        return get_ans(0,nums);
        
    }
};