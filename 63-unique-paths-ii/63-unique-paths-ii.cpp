class Solution {
public:
    int dp[101][101];
    int ans(vector<vector<int>>OG,int &m,int &n,int curr_r,int curr_c)
    {
        if(curr_r>=m || curr_c>=n || OG[curr_r][curr_c]==1)
            return 0;
        
        if( curr_r==m-1 && curr_c==n-1)
            return 1;
           
        if(dp[curr_r][curr_c]!=-1)
            return dp[curr_r][curr_c];
        
        int down=ans(OG,m,n,curr_r+1,curr_c);
        int right=ans(OG,m,n,curr_r,curr_c+1);
        
        dp[curr_r][curr_c]= down + right;
        
        return dp[curr_r][curr_c];
        
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& OG) {
        int m=OG.size();
        int n=OG[0].size();
        
        memset(dp,-1,sizeof(dp));
        
        return ans(OG,m,n,0,0);
         
    }
};