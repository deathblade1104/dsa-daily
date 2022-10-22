class Solution {
public:
    int dp[2001];
    int palinDP[2001][2001];
    
    int isPalinHelper(int i,int j, string &s){
        
        if(i==j)
            return palinDP[i][j] = true;
        if(i == j-1)
            return palinDP[i][j] = (s[i]==s[j])? true : false;
        
        if(palinDP[i][j]!=-1)
            return palinDP[i][j];
        
        bool ans = false;
        
        if(s[i] == s[j])
            ans = true & isPalinHelper(i+1,j-1,s);
        
        bool x = isPalinHelper(i+1,j,s) , y = isPalinHelper(i,j-1,s);
        
        return palinDP[i][j] = ans;
    }
    
    int helper(int curr,string&s){
        
        if(curr>=s.size())
            return -1;
        
        if(dp[curr]!=-1)
            return dp[curr];
        
        int ans = INT_MAX;
        
        for(int i=curr;i<s.size();i++){
            if(palinDP[curr][i]){
                int t = 1 + helper(i+1,s);
                ans = min(ans,t);
            }
        }
        
        return dp[curr] = ans;
    }
    int minCut(string s) {
        memset(palinDP,-1,sizeof palinDP);
        memset(dp,-1,sizeof dp);
        int x = isPalinHelper(0,(int)s.size()-1,s);
        return helper(0,s);
        
    }
};