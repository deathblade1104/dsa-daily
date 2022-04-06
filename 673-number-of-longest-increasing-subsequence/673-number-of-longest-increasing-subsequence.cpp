class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        vector<int>count(n,1);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                    // dp[i]= max(dp[i], 1 + dp[j]);
                {
                    if(dp[i]<dp[j]+1)
                    {
                        dp[i]=dp[j]+1;
                        count[i]=count[j];
                    }
                    
                    else if(dp[i]==dp[j]+1)
                        count[i]+=count[j];
                }
            }
            ans=max(ans,dp[i]);
        }
        int x=0;
        for(int i=0;i<n;i++)
            if(dp[i]==ans)
                x+=count[i];
        
        return x;
    }
};