class Solution {
public:
    
    int get_ans(int i, int j,int&m ,int&n, vector<vector<int>>&dp)
    {
        if(i>=m or j>=n)
            return 0;
        
        if(i==m-1 and j==n-1)
            return 1;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int left,down;
        
        left = down = 0;
        
        left = get_ans(i,j+1,m,n,dp);
        down = get_ans(i+1,j,m,n,dp);
             
        return dp[i][j]= left + down;
            
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        
        return get_ans(0,0,m,n,dp);
    }
};