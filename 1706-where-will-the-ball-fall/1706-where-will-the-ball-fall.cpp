class Solution {
public:

    int helper(int r,int c,int&n,int&m,vector<vector<int>>&grid,vector<vector<int>>&dp){
        
        if(dp[r][c]!=-2)
            return dp[r][c];
        
        int ans = -5;
        
        if(grid[r][c]==-1){
            
            if(c==0 or grid[r][c-1]==1)
                ans = -1;
            
            else{
                
                if(r+1 == n)
                    ans = c-1;
                
                else
                    ans = helper(r+1,c-1,n,m,grid,dp);
                    // ans = -6;
            }
        }
        
        else {
            
            if(c==m-1 or grid[r][c+1]==-1)
                ans = -1;
            
            else{
                
                if(r+1 == n)
                    ans = c+1;
                
                else
                    ans = helper(r+1,c+1,n,m,grid,dp);
                    //ans = - 7;
            }
        }
        
        return dp[r][c] = ans;
    }
    
    vector<int> findBall(vector<vector<int>>& grid) {
       
        int n = grid.size(),m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-2));
        
        vector<int>ans(m,-1);
        
        for(int i=0;i<m;i++)
            ans[i] = helper(0,i,n,m,grid,dp);
        
        return ans;
    }
};