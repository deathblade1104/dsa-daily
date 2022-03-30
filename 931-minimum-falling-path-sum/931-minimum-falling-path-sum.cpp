class Solution {
public:

    int get_ans(int r, int c, int &n,vector<vector<int>>& matrix,vector<vector<int>>& dp)
    {
        if(r>=n or c<0 or c>=n) return INT_MAX/2;
        
        if(r==n-1 and (c>=0 and c<=n-1))
            return dp[r][c] = matrix[r][c];
        
        if(dp[r][c]!=INT_MAX/2)
            return dp[r][c];
        
        int op1,op2,op3;
        op1=op2=op3=matrix[r][c];
        
        op1+= get_ans(r+1,c-1,n,matrix,dp);
        op2+= get_ans(r+1,c,n,matrix,dp);
        op3+= get_ans(r+1,c+1,n,matrix,dp);
        
        return dp[r][c]=min({op1,op2,op3});
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size(),ans=INT_MAX;
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX/2));
            
        for(int i=0;i<n;i++)
            ans=min(ans,get_ans(0,i,n,matrix,dp));    
        return ans;
        
    }
};