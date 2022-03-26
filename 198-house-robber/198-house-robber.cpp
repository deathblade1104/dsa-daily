class Solution {
private:
    int dp[101];
    int get_ans(int curr, int sz, vector<int>&nums)
    {
        if(curr>=sz)
            return 0;
        
        if(dp[curr]!=-1)
            return dp[curr];
        
        int rob = nums[curr] + get_ans(curr+2,sz,nums); 
        int dont_rob = get_ans(curr+1,sz, nums);
        
    
        dp[curr]= max(rob,dont_rob);
        
        return dp[curr];
    }
public:
    int rob(vector<int>& nums) {
        int sz=nums.size();
        memset(dp,-1, sizeof(dp));
        
        return get_ans(0,sz,nums);
        
        
    }
};