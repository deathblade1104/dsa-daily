class Solution {
public:
    int dp[10][2][10];
    string s;
    
    int helper(int pos, bool tight, int count){
        
        if(pos == s.size())
            return count;
        
        if(dp[pos][tight][count]!=-1)
            return dp[pos][tight][count];
        
        int ans = 0;
        
        int upperBound = tight ? s[pos] - '0' : 9;
        
        for(int i=0;i<=upperBound;i++){
            
            if(i==1)
             ans+= helper(pos+1,tight&(i==upperBound),count+1);
            
            else
            ans+= helper(pos+1,tight&(i==upperBound),count);
        }
        
        return dp[pos][tight][count] = ans;
    }
    
    int countDigitOne(int n) {
        
        s = to_string(n);
        memset(dp,-1,sizeof dp);
        
        return helper(0,1,0);
        
        
    }
};