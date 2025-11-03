class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>dp(n+1,0);

         for(int i=1;i<=n;i++)
        {
            dp[i]=dp[i/2];
            
            if(i&1)
                dp[i]++;
        }
        
        return dp; 
        
    }
};