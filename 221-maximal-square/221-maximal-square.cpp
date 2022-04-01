class Solution {
public:
    int dp[301][301];
    
    int get_ans(int r,int c, int&n, int &m, vector<vector<char>>&grid)
    {
        if(r>=n or c>=m or grid[r][c]=='0')
            return 0;
        
        if(dp[r][c]!=-1)
            return dp[r][c];
        
        int op1,op2,op3;
        op1=op2=op3=1;        
        
        op1+=get_ans(r+1,c,n,m,grid);
        op2+=get_ans(r,c+1,n,m,grid);
        op3+=get_ans(r+1,c+1,n,m,grid);
        
        return dp[r][c] = min({op1,op2,op3});
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        memset(dp,-1,301*301*sizeof(int));
        
        int ans=0,n=matrix.size(),m=matrix[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='1')
                    ans=max(ans,get_ans(i,j,n,m,matrix));
            }
        }
        
        return ans*ans;
    }
};