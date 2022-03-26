class Solution {
private:
    int dp[101];
    int get_ans(int curr, int sz, vector<int>&nums)
    {
        if(dp[curr]!=-1)
            return dp[curr];
        
        int rob = nums[curr] ,dont_rob =0;
        
        if(curr+2<sz)
            rob += get_ans(curr+2,sz,nums);
        
        if(curr+1<sz)
            dont_rob += get_ans(curr+1,sz,nums);
        
        return dp[curr]= max(rob,dont_rob);
    }
    
public:
    int rob(vector<int>& nums) {
        int sz=nums.size();
        memset(dp,-1, sizeof(dp));
        
        return get_ans(0,sz,nums);
        
        
    }
};