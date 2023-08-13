class Solution {
public:
    int dp[101][101];
    int m;
    int helper(int r, int c,vector<vector<int>>& mat){
        
        if(c<0 or c>=m)
            return INT_MAX/2;
        
        // if(r== m-1)
        //     return mat[r][c];
        
        if(dp[r][c]!=INT_MAX)
            return dp[r][c];
        
        return dp[r][c] = mat[r][c] + min({helper(r+1,c,mat), helper(r+1,c-1,mat),helper(r+1,c+1,mat)});
    }
    
    int minFallingPathSum(vector<vector<int>>& mat) {  
        int ans = INT_MAX;
        m = mat.size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                dp[i][j] = INT_MAX;
            }
        }
        
        for(int i=0;i<m;i++){
            dp[m-1][i] = mat[m-1][i];
        }
        
        for(int i=0;i<m;i++)
            ans = min(ans,helper(0,i,mat));
        
        return ans;
    }
};