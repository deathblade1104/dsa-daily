class Solution {
public:
    
    int dp[100001][3];
    const int mod = 1e9 + 7;
    
    int helper(int pos,int prev,int&zeroes,int&ones,int&sz){
        
        if(pos >sz)
            return 0;
        
        if(dp[pos][prev]!=-1)
            return dp[pos][prev];
        
        int ans = 1;
        
        ans+=(helper(pos+zeroes,1,zeroes,ones,sz)%mod + helper(pos+ones,2,zeroes,ones,sz)%mod)%mod;
        
        return dp[pos][prev] = ans;
    }
    
    int countGoodStrings(int low, int high, int zero, int one) {
        
        memset(dp,-1,sizeof dp);
        
        int ans = helper(0,0,zero,one,high);
        //cout<<"ANS 1 -->"<<ans<<endl;
        
        if(low!=0)
        {
            memset(dp,-1,sizeof dp);
            low--;
            ans-=helper(0,0,zero,one,low);
        }        
    
       // cout<<"ANS 2-->"<<ans<<endl;
        
        if(ans<0)
            ans+=mod;
        
        return ans;
    
        
    }
};