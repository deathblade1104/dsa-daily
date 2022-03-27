class Solution {
public:
    int dp[10001];
    int coinChange(vector<int>& coins, int amt) {
        memset(dp,10000,10001*sizeof(int));        
        int n=coins.size();
        sort(coins.begin(),coins.end());
        
        if(amt == 0 )
            return 0;
        
        if(coins[0]>amt)
            return -1;
        
        for(int i=0;i<n;i++)
        {
            if(coins[i]<=amt)
                dp[coins[i]]=1;
            
            else break;
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