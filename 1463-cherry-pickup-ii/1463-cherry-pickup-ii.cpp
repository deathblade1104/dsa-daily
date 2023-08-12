class Solution {
public:
    int dp[71][71][71];
    int n,m;
    
    bool isCellValid(int r,int c){
        
        if(r>=n or c>=m or c<0)
            return false;
        
        return true;
        
    }
    int helper(int r1,int c1,int c2,vector<vector<int>>& mat ){
        
        int r2 = r1;
        
        if(!isCellValid(r1,c1) || !isCellValid(r2,c2))
            return 0;
        
        
        if(dp[r1][c1][c2]!=-1)
            return dp[r1][c1][c2];
        
        int currCherry = mat[r1][c1];
        
        if(r1!=r2 || c1!=c2)
            currCherry+=mat[r2][c2];
        
        int op1 = helper(r1+1,c1,c2-1,mat);
        int op2 = helper(r1+1,c1,c2,mat);
        int op3 = helper(r1+1,c1,c2+1,mat);
        
        int op4 = helper(r1+1,c1-1,c2-1,mat);
        int op5 = helper(r1+1,c1-1,c2,mat);
        int op6 = helper(r1+1,c1-1,c2+1,mat);
        
        int op7 = helper(r1+1,c1+1,c2-1,mat);
        int op8 = helper(r1+1,c1+1,c2,mat);
        int op9 = helper(r1+1,c1+1,c2+1,mat);
        
        int maxOp = max({op1,op2,op3,op4,op5,op6,op7,op8,op9});
     
        return dp[r1][c1][c2] = maxOp + currCherry;
    }
    int cherryPickup(vector<vector<int>>& mat) {
        n = mat.size();
        m = mat[0].size();
        memset(dp,-1,sizeof dp);
        
        return helper(0,0,m-1,mat);
        
        
    }
};