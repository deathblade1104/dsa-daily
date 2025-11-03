class Solution {
public:
    
    int dp[101];
    
    int helper(int pos,string&s){
        
        if(pos==s.size())
            return 1;
        
        if(pos>s.size() or s[pos]=='0')
            return 0;
        
        if(dp[pos]!=-1)
            return dp[pos];
        
        int ans=0;
        ans+=helper(pos+1,s);
        
        if(pos<s.size()-1 and ((s[pos]-'0')*10 + (s[pos+1]-'0') <=26))
        ans+=helper(pos+2,s);
        
        return dp[pos]= ans;
    }
    
    int numDecodings(string s) {
        
        memset(dp,-1,sizeof dp);
        return helper(0,s);
        
    }
};