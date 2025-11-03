class Solution {
public:
    
    int dp[201][201];
    int helper(int r,int c,int&sz,vector<vector<int>>&mat){
        
        if(r>=sz)
            return 0;
        
        if(c>=mat[r].size())
            return INT_MAX/2;
        
        if(dp[r][c]!=-1)
            return dp[r][c];
        
        return dp[r][c] = mat[r][c] + min(helper(r+1,c,sz,mat), helper(r+1,c+1,sz,mat));    
    }
    
    
    int minimumTotal(vector<vector<int>>& mat) {
        memset(dp,-1,sizeof dp);
        int sz = mat.size();
        
        return helper(0,0,sz,mat);
    }
};