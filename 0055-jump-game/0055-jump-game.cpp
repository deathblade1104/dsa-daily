class Solution {
public:
    int dp[1000001];
    int get_ans(int curr, int&sz ,vector<int>&nums)
    {
        if(curr>=sz-1)
            return 1;
        
        if(dp[curr]!=-1)
            return dp[curr];
        
        for(int i=nums[curr];i>=1;i--)
        {
            bool temp = get_ans(curr+i,sz,nums);
            if(temp)
                return dp[curr]=1;    
        }        
        return dp[curr]=0;
    }
    
    bool canJump(vector<int>& nums) {
        int sz=nums.size();
        memset(dp,-1,sizeof(dp));
        
        return get_ans(0,sz,nums);
        
    }
};