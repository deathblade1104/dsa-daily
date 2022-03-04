class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        
        if(poured==0)
            return 0;        
        double dp[101][101]={0.0};        
        dp[0][0]= poured + 0.0;        
        for(int i=0;i<=query_row;i++)
        {
            for(int j=0;j<=i and j<=query_glass;j++)
            {
                if(dp[i][j]>1.0)
                {
                    double res = dp[i][j]- 1.0;
                    dp[i][j]=1.0;
                    dp[i+1][j]+= res/2.0;
                    dp[i+1][j+1]+= res/2.0;                    
                }                
            }
        }
        
        return dp[query_row][query_glass];
        
        
        
    }
};