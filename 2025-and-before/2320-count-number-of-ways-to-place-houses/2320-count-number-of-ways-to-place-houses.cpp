class Solution {
public:
    const long long mod = 1e9 + 07;
    long long dp[10001][2];
    
    long long helper(int curr,bool occupied,int&n){
        
        if(curr==n)
            return 1;
        
        if(dp[curr][occupied]!=-1)
            return dp[curr][occupied];
        
        
        long long ans = 0;
        ans += helper(curr+1,!occupied,n);
        ans%=mod;
        
        if(!occupied){
         ans += helper(curr+1,occupied,n);
         ans%=mod;
        }
        
        return dp[curr][occupied] = ans;
    }
    
    int countHousePlacements(int n) {
        
        memset(dp,-1*1LL, sizeof dp);
        long long ans = helper(0,0,n);
        ans%=mod;
        ans*=ans;
        ans%=mod;
        
        if(ans<0)
            ans+=mod;
        
        
        return (int)ans;
        
        
    }
};