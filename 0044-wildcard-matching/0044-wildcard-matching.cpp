class Solution {
public:
    
    int n,m,dp[2001][2001];
    
    bool helper(int i, int j, string&s,string&p){
        
        if(j>=m)
            return i>=n;
        
        if(i>=n)
            return p[j]=='*' && helper(i,j+1,s,p);
            
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(p[j] == '?' || s[i]==p[j]){
            return dp[i][j] = helper(i+1,j+1,s,p);
        }
        
        if (p[j] == '*' ){
            bool op1 = helper(i+1,j,s,p);
            if(op1)
                return dp[i][j] = true;
            
            return dp[i][j] = helper(i,j+1,s,p);
        }
        
        return dp[i][j] = false;
    }
    
    bool isMatch(string s, string p) {
        n = s.size();
        m  = p.size();
        
        memset(dp,-1,sizeof dp);
        
        return helper(0,0,s,p);
    }
};