class Solution {
public:
    int coinChange(vector<int>& nums, int sum) {
    
    int n  = nums.size();
    vector<int>dp(sum+1,sum+1);
    sort(nums.begin(),nums.end());
    dp[0]=0;

    for(int i=1;i<=sum;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(nums[j]>i)
                break;

            dp[i] = min(dp[i], 1 + dp[i - nums[j]]);
        }
        // cout<<i<<" "<<dp[i]<<endl;
    }

    
    int ans = dp[sum];
    if(ans  == sum+1)
        ans = -1;

    return ans;
        
    }
};