class Solution {
public:
    int dp[2001];
    int n;
    string s;
    static const int mod = 1e9 + 7;
    
    int helper(int curr){
        
        if(curr>=n)
            return 0;
 
        int&ans = dp[curr];
        
        if(ans!=-1)
            return ans;
        
        ans = 0;
        bool vis[26];
        memset(vis,0,sizeof vis);
        
        
        for(int i=curr;i<n;i++){
            int idx = s[i] - 'a';
            
            if(vis[idx])
                continue;
            
            int curr = 1 + helper(i+1);
            vis[idx]= 1;
            ans = (ans%mod + curr%mod)%mod;
        }
    
        return ans;
    }
    int distinctSubseqII(string s) {
        memset(dp,-1,sizeof dp);    
        n = s.size();
        this->s = s;
        return helper(0);
        
        
    }
};