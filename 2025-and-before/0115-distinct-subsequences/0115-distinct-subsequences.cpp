class Solution {
public:
    int n,m;
    int dp[1001][1001];
    int helper(int i,int j,string&s,string&t){
        
        if(j>=m)
            return 1;
        
        if(i>=n)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int op1,op2;
        op1 = op2 = 0;
        
        //consider
        if(s[i]==t[j])
            op1 = helper(i+1,j+1,s,t);
        
        //dontConsider 
        op2 = helper(i+1,j,s,t);
        
        return dp[i][j] =  op1 + op2;
    }
    int numDistinct(string s, string t) {
        n = s.size();
        m = t.size();
        memset(dp,-1,sizeof dp);
        return helper(0,0,s,t);
    }
};