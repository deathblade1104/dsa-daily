class Solution {
public:
    const int mod = 1e9+ 7;
    int finalState,n;
    int dp[100001][16];
    
    int helper(int curr,int mask){
        
        if(curr>=n)
            return mask == finalState;
        
        if(dp[curr][mask]!=-1)
            return dp[curr][mask];
        
        int ans = 0,op1,op2,op3,op4,newMask,index;
        
        //for l
        newMask = (mask | (1<<0));
        op1 = helper(curr+1,newMask);
        
        
        //for e
        index = ((mask&(1<<1)) == 0) ? 1  : 2;
        newMask = (mask | (1<<index)); 
        op2 = helper(curr+1,newMask);
        
        //for t
        newMask = (mask | (1<<3));
        op3 = helper(curr+1,newMask);
        
        //for all other chars
        newMask = mask;
        op4= helper(curr+1,newMask);
        
        
        ans = (ans%mod + op1%mod)%mod;
        ans = (ans%mod + op2%mod)%mod;
        ans = (ans%mod + op3%mod)%mod;
        ans = (ans%mod + (1LL * 23 * op4)%mod)%mod;
        
        return dp[curr][mask] = ans;
    }
    
    
    int stringCount(int N) {
        n =N;
        finalState = (1<<4) -1;
        memset(dp,-1,sizeof dp);
        
        return helper(0,0);
    
    }
};