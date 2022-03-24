class Solution {
public:
    int dp[10001];
    int get_ans(int curr,int &sz,vector<int>&nums)
    {
        if(curr>=sz-1)
            return 0;
        
        if(dp[curr]!=-1)
            return dp[curr];
        
        int ans=(INT_MAX/2);
        
        if(nums[curr]==0)
            return dp[curr]=ans;
        
        for(int i=nums[curr];i>=1;i--)
        {
            int temp = 1 + get_ans(curr+i,sz,nums);
            ans=min(ans,temp);
        }
        
        return dp[curr]=ans;
    }
    int jump(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int sz= nums.size();
        
        return get_ans(0,sz,nums);
    }
};