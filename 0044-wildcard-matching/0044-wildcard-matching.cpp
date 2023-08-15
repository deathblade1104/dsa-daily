class Solution {
public:
    
    int n,m,dp[2002][2002];
    
    bool helper(int i, int j, string&s,string&p){
        
        if(j>=m)
            return i>=n;
        
        if(i>=n){
             while(j<m) {
                if(p[j] != '*')
                    return dp[i][j] = false;
                j++;
            }
            return dp[i][j] = 1;
        }
            
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        bool match = (s[i] == p[j]) || (p[j] == '?');

        if (p[j] == '*') {
            bool op1 = helper(i + 1, j, s, p); 
            
            if(op1)
                return dp[i][j] = true;
            
            return dp[i][j] = helper(i, j + 1, s, p); 
            
        }

        return dp[i][j] = match && helper(i + 1, j + 1, s, p);
    }
    
    bool isMatch(string s, string p) {
        
        n = s.size();
        m  = p.size();
        
         
        memset(dp,-1,sizeof dp);
        
        return helper(0,0,s,p);
    }
};