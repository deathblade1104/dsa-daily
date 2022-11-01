class Solution {
public:
    int dp[101][101];
    int helper(int r,int c,int&n,int&m,vector<vector<int>>&grid){
        
        if(dp[r][c]!=-1)
            return dp[r][c];
        
        int ans = -1;
        
        if(grid[r][c]==-1){
            
            if(c==0 or grid[r][c-1]==1)
                ans = -101;
            
            else{
                
                if(r+1 == n)
                    ans = c-1;
                
                else
                    ans = helper(r+1,c-1,n,m,grid);
            }
        }
        
        else {
            
            if(c==m-1 or grid[r][c+1]==-1)
                ans = -101;
            
            else{
                if(r+1 == n)
                    ans = c+1;
                
                else
                    ans = helper(r+1,c+1,n,m,grid);
            }
        }
        
        return dp[r][c] = ans;
    }
    
    vector<int> findBall(vector<vector<int>>& grid) {
       
        int n = grid.size(),m = grid[0].size();
        memset(dp,-1,sizeof dp);
        
        vector<int>ans(m);
        
        for(int i=0;i<m;i++){
           int x = helper(0,i,n,m,grid);
           ans[i]= (x == -101) ? -1 : x;
        }
        
        return ans;
    }
};