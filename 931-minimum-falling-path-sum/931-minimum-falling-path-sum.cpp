class Solution {
public:
    int dp[101][101];
    int get_ans(int r, int c, int &n,int &m, vector<vector<int>>& matrix,vector<vector<int>>&dp)
    {
        if(r>=n or c<0 or c>=m) return INT_MAX/2;
        
        if(r==n-1 and (c>=0 and c<=m-1))
            return dp[r][c] = matrix[r][c];
        
        if(dp[r][c]!=INT_MAX/2)
            return dp[r][c];
        
        int op1,op2,op3;
        op1=op2=op3=matrix[r][c];
        
        op1+= get_ans(r+1,c-1,n,m,matrix,dp);
        op2+= get_ans(r+1,c,n,m,matrix,dp);
        op3+= get_ans(r+1,c+1,n,m,matrix,dp);
        
        return dp[r][c]=min({op1,op2,op3});
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX/2));
        
        int ans=INT_MAX;        
        for(int i=0;i<n;i++)
            ans=min(ans,get_ans(0,i,n,n,matrix,dp));
        
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<n;j++)
               cout<<dp[i][j]<<" ";
           
           cout<<endl;
       }
    
        return ans;
        
    }
};