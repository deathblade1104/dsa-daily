class Solution {
public:
    int dp[501][501];
    
    int helper(int i,int j,string&s)
    {
        if(i>=j)
            return 0;
        
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        
        int ans = 0;
        if(s[i] == s[j])
            ans = helper(i+1,j-1,s);
        
        else{
            int op1 = 1 +  helper(i+1,j,s);
            int op2 = 1 + helper(i,j-1,s);
            
            ans = min(op1,op2);
        }
        
        return dp[i][j] = ans;
    }
    int minInsertions(string s) {
        
        memset(dp,-1,sizeof dp);
        int n = s.size() -1;
        return helper(0,n,s);
    }
};