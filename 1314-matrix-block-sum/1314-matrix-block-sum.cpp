class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        
   int n = mat.size(), m = mat[0].size();
        vector<vector<int>> prefix(n, vector<int>(m, 0));
        
        for (int i = 0 ; i < n ; i++){
            for (int j = 0 ; j < m ; j++){
                prefix[i][j] = (j > 0 ? prefix[i][j-1] + mat[i][j] : mat[i][j]);
            }
        }
        
        vector<vector<int>>dp(n, vector<int>(m, 0));
        
        for (int i = 0 ; i < n ; i++){
            for (int j = 0 ; j < m ; j++){
                dp[i][j] = (i > 0 ? dp[i-1][j] : 0) + prefix[i][j];
            }
        }
        
        vector<vector<int>> ans(n, vector<int>(m, 0));
        
        for (int i = 0 ; i < n ; i++){
            for (int j = 0 ; j < m ; j++){
                int top_row = min(i + k, n - 1), top_col = min(j + k, m - 1);
                int down_row_top_col = (i - k - 1 < 0 ? 0 : dp[i-k-1][top_col]);
                int top_row_down_col = ( j -k - 1 < 0 ? 0 : dp[top_row][j-k-1]);
                int down_row_down_col = ( i- k - 1 < 0 || j - k -1 < 0 ? 0 : dp[i-k-1][j-k-1]);
                
                ans[i][j] = dp[top_row][top_col] - down_row_top_col - top_row_down_col + down_row_down_col;
            }
        }
        return ans;
        
    }
};