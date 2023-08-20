class Solution {
public: 
    int dp[2001][2001];
    int N,M;
    
    
    bool helper(int i,int j,string&s,string&p){
        
        if(j>=M)
            return i>=N;
        
        if(i>=N){
             while(j<M) {
                if(p[j] != '*')
                    return dp[i][j] = false;
                j++;
            }
            return dp[i][j] = true;
        }
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(s[i]==p[j] or p[j]=='?')
            return dp[i][j] = helper(i+1,j+1,s,p);
        
        else if(p[j] == '*'){
            
            bool op1 = helper(i + 1, j, s, p); 
            
            if(op1)
                return dp[i][j] = true;
            
            return dp[i][j] = helper(i, j + 1, s, p); 
        }
            
        else return dp[i][j] = false;
        
    }
    bool isMatch(string s, string p) {
        
        N = s.size();
        M = p.size();
        
        memset(dp,-1,sizeof dp);
        
        return helper(0,0,s,p);
        
    }
};