class Solution {
public:
    int dp[10001];
    int coinChange(vector<int>& coins, int amt) {
        memset(dp,10000,10001*sizeof(int));
        dp[0]=0;
        
        int n=coins.size();
        
        sort(coins.begin(),coins.end());
        
        for(int i=0;i<n;i++)
        {
            if(coins[i]<=10000)
                dp[coins[i]]=1;
        }
        
        dp[0]=0;
        
        
        for(int i=1;i<=amt;i++)
        {
            if(dp[i]!=10001)
            {
                int temp =10001;
                for(int j=0; j<n;j++)
                {
                    if(coins[j]<=i)
                    temp = min(temp,dp[i-coins[j]]);
                    
                    else
                    break;
                }
                
                dp[i] = temp + 1;
            }
        }
        
        if(dp[amt]>=10000)
            return -1;
        
        return dp[amt];
    }
};