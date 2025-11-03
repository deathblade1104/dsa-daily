class Solution {
public:
    int dp[101][101];
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n=mat.size(),m=mat[0].size();
        memset(dp,0,101*101*sizeof(int));
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + mat[i-1][j-1]; 
            }
        }
        
        vector<vector<int>>ans(n,vector<int>(m,0));
    
        for(int i =0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int start_r,start_c,end_r,end_c;
                start_r = max(0,i-k);
                start_c = max(0,j-k);
                
                end_r = min(n,i+k+1);
                end_c = min(m,j+k+1);
                
                ans[i][j] = dp[end_r][end_c] - dp[end_r][start_c] - dp[start_r][end_c] + dp[start_r][start_c];
            }
        }
        
        return ans;
        
        
        
        
        
    }
};