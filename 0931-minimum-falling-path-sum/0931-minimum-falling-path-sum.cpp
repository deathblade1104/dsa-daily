class Solution {
public:
    int dp[101][101];
    
    int helper(int i, int j, int&n, vector<vector<int>>&matrix){
        
        if(j<0 or j>=n)
            return 10001;
        
        if(i == n-1)
            return dp[i][j] = matrix[i][j];
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        return dp[i][j] = matrix[i][j] + min({
            helper(i+1,j-1,n,matrix),
            helper(i+1,j,n,matrix),
            helper(i+1,j+1,n,matrix)
        });
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        memset(dp,-1,sizeof dp); 
        
        int n = matrix.size(),ans = INT_MAX;
        
        for(int i=0;i<n;i++)
            ans= min(ans,helper(0,i,n,matrix));
        
        return ans;
    }
};