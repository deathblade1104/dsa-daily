class Solution {
public:
   
    int n;
    string s;
    static const int maxN=1e5+1,sofa=3,mod=1e9 + 7;
    int dp[maxN][sofa];
    
    int helper(int curr,int count){
        
        if(curr>=n)
            return count==2;
        
        int &ans = dp[curr][count];
        
        if(ans != -1)
            return ans;
        
        ans = 0;
        int isSofa = s[curr] == 'S' ? 1: 0;
        
        if(count == 2){
            
            if(isSofa)
                ans= (ans%mod + helper(curr+1,isSofa)%mod);
            
            else {
                ans=(ans%mod + helper(curr+1,0)%mod)%mod;
                ans=(ans%mod + helper(curr+1,2)%mod)%mod;
            }
        }
        
        else ans= (ans%mod + helper(curr+1,count+isSofa)%mod);
        
        return ans;
    }
        
    int numberOfWays(string s) {

        n = s.size();
        this->s = s;
        memset(dp,-1,sizeof dp);
        return helper(0,0);
    }
};