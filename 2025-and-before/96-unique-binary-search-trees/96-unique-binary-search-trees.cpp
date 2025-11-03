class Solution {
public:
    int numTrees(int n) {
        int dp[20]={-1};
        dp[0]=1;
        dp[1]=1;
        
        for(int i=2;i<=n;i++)
        {
            int j=0,k=i-1;
            int temp=0;
            while(k>=0)
            {
                temp+=(dp[k]*dp[j]);
                k--;
                j++;
            }
            dp[i]=temp;
        }
        
        return dp[n];
    }
};