class Solution {
public:
    int dp[2001][4];
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
    
    int helper(int curr, int part,string&s){
        
        if(curr==s.size())
            return (part == 3) ? true : false;
        
        
        if(dp[curr][part]!=-1)
            return dp[curr][part];
        
        for(int i=curr;i<s.size();i++){
            
            if(palinDP[curr][i] and part<3){
                bool temp = true & helper(i+1,part+1,s);
        
                if(temp)
                    return dp[curr][part] = true;   
            }
        }
        
        return dp[curr][part] = false;
    }
    bool checkPartitioning(string s) {
        
        if(s.size() == 3)
            return true;
        
        memset(palinDP,-1,sizeof palinDP);
        memset(dp,-1,sizeof dp);
        
        int x = isPalinHelper(0,s.size()-1,s);
        
        return helper(0,0,s);
    }
};