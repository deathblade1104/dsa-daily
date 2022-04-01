class Solution {
public: 
    int dp[201][201];
    
    int get_ans(int r, int c, int &n,vector<vector<int>>&grid)
    {
        if(r==n-1) return grid[r][c];
        
        if(dp[r][c]!=-1)
            return dp[r][c];
        
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(c==i)
                continue;
            
            int curr = get_ans(r+1,i,n,grid);
            ans=min(curr,ans);
        }
        
        return dp[r][c] = ans +  grid[r][c];
    }
    
    int minFallingPathSum(vector<vector<int>>& grid) {
    
        int ans=INT_MAX, n=grid.size();
        memset(dp,-1,201*201*sizeof(int));
        
        for(int i=0;i<n;i++)
        {
            int temp = get_ans(0,i,n,grid);
            ans=min(ans,temp);
        }
        
        
        return ans;
     
    }
};