class Solution {
public:
    int get_ans(int curr, int sz, vector<int>&nums,vector<int>&dp)
    {
        if(dp[curr]!=-1)
            return dp[curr];
        
        int rob = nums[curr] ,dont_rob =0;
        
        if(curr+2<sz)
            rob += get_ans(curr+2,sz,nums,dp);
        
        if(curr+1<sz)
            dont_rob += get_ans(curr+1,sz,nums,dp);
        
        return dp[curr]= max(rob,dont_rob);
    }
    
    int rob(vector<int>& nums) {
        int sz=nums.size();
        vector<int>dp1(sz,-1),dp2(sz,-1);
        
        if(sz==1)
            return nums[0];
            
        return max(get_ans(0,sz-1,nums,dp1),get_ans(1,sz,nums,dp2));
        
        
    }
};