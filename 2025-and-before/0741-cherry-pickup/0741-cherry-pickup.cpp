class Solution {
public:
    int n;
    int dp[51][51][51];
    
    int helper(int r1,int c1,int r2,vector<vector<int>>& mat ){
        
        int c2 = r1-r2+c1;
        
        if(r1>=n or c1>=n or r2>=n or c2>=n or mat[r1][c1]==-1 or mat[r2][c2]==-1)
            return INT_MIN;
        
        if(r1==n-1 and c1==n-1 and r2==n-1 and c2==n-1)
            return dp[r1][c1][r2] = mat[r1][c1];
        
        if(dp[r1][c1][r2]!=-1)
            return dp[r1][c1][r2];
        
        int currCherry = mat[r1][c1];
        
        if(r1!=r2 || c1!=c2)
            currCherry+=mat[r2][c2];
        
        int op1 = helper(r1+1,c1,r2+1,mat);
        int op2 = helper(r1,c1+1,r2+1,mat);
        int op3 = helper(r1+1,c1,r2,mat);
        int op4 = helper(r1,c1+1,r2,mat);
        
        int maxOp = max({op1,op2,op3,op4});
        
        if(maxOp == INT_MIN)
            return dp[r1][c1][r2] = maxOp;
        
        return dp[r1][c1][r2]= maxOp + currCherry;
    }
    int cherryPickup(vector<vector<int>>& mat) {
        n = mat.size();
        memset(dp,-1,sizeof dp);
        int ans = helper(0,0,0,mat);
        return ans == INT_MIN ? 0 : ans;
    }
};