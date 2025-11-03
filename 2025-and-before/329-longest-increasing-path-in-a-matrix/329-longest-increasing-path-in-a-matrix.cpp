class Solution {
public:
    int DFS(int i,int j,int&n,int&m, int prev,array<int,5>&dir,vector<vector<int>>&matrix, vector<vector<int>>&dp)
    {
        if(i<0 or j<0 or i>=n or j>=m or matrix[i][j]<=prev)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        
        int ans =0;
        
        for(int k=1;k<=4;k++)
            ans= max(ans,DFS(i+dir[k-1],j+dir[k],n,m,matrix[i][j],dir,matrix,dp));
            
        
        return dp[i][j]= ans + 1;   
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int n = matrix.size(),m=matrix[0].size();
        
        array<int,5>dir = {1,0,-1,0,1};
        vector<vector<int>>dp(n,vector<int>(m,-1));
        
        int ans =0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(dp[i][j]!=-1)
                    ans= max(ans,dp[i][j]);
                
                else
                    ans = max(ans,DFS(i,j,n,m,-1,dir,matrix,dp));
            }
        }
        
        return ans;
    }
};