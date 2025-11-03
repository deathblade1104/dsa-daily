class Solution {
public:
    int dp[201][201];
    bool dp2[201][201];
    int m,n;
    int helper(int r, int c,vector<vector<int>>& mat){
        
        if(r>=m or c>=n)
            return INT_MIN;
        
        if(r==m-1 and c==n-1)
            return mat[r][c];
        
        if(dp[r][c]!=-1 and dp2[r][c] == true)
            return dp[r][c];
        
        int op1 = helper(r+1,c,mat);
        int op2 = helper(r,c+1,mat);
        dp2[r][c] = true;
        return dp[r][c] = min(mat[r][c],mat[r][c] + max(op1,op2));
        
    }
    int calculateMinimumHP(vector<vector<int>>& mat) {
        memset(dp,-1,sizeof dp);
        memset(dp2,0,sizeof dp2);
        m = mat.size();
        n = mat[0].size();
        
        
        int ans = helper(0,0,mat);
        
        if(ans>=0)
            return 1;
        
        return abs(ans) + 1;
    }
};