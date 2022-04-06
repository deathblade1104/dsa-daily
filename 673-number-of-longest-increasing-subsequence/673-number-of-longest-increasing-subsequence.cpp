class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size(),ans=0,x=0;
        vector<int>dp(n,1),count(n,1);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
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

        for(int i=0;i<n;i++)
            if(dp[i]==ans)
                x+=count[i];
        
        return x;
    }
};