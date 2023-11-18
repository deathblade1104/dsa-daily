class Solution {
public:
    const long long int mod = 1e9+ 7;
    int finalState,n;
    long long int dp[100001][16];
    
    long long int helper(int curr,int mask){
        
        if(curr>=n)
            return 1LL * (mask == finalState);
        
        if(dp[curr][mask]!=-1)
            return dp[curr][mask];
        
        long long  int ans = 0LL,op1,op2,op3,op4;
        int newMask,index;
        
        newMask = (mask | (1<<0));
        op1 = helper(curr+1,newMask);
        
        index = ((mask&(1<<1)) == 0) ? 1  : 2;
        newMask = (mask | (1<<index)); 
        op2 = helper(curr+1,newMask);
        
        newMask = (mask | (1<<3));
        op3 = helper(curr+1,newMask);
        
        newMask = mask;
        op4= helper(curr+1,newMask);
        
        
        ans = (ans%mod + op1%mod + op2%mod + op3%mod + (23*op4)%mod)%mod;
        
        
        return dp[curr][mask] = ans;
    }
    
    
    int stringCount(int N) {
        n =N;
        finalState = (1<<4) -1;
        memset(dp,-1,sizeof dp);
        
        return helper(0,0);
    
    }
};