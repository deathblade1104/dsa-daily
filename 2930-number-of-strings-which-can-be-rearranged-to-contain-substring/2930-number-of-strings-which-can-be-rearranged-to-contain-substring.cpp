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
        
        int ans = 0;
        for(char ch='a';ch<='z';ch++){
            
          int newMask,index;
            
            switch(ch){
                    
                case 'l':
                    newMask = (mask | (1<<0));
                    break;
                
                case 't' :
                    newMask = (mask | (1<<3));
                    break;
                
                case 'e' : 
                    index = ((mask&(1<<1)) == 0) ? 1  : 2;
                    newMask = (mask | (1<<index));        
                    break;
                
                default: 
                    newMask = mask;
                    break;
            }
            
            ans = (ans%mod + helper(curr+1,newMask)%mod)%mod;
        }
        
        return dp[curr][mask] = ans;
    }
    
    
    int stringCount(int N) {
        n =N;
        finalState = (1<<4) -1;
        memset(dp,-1,sizeof dp);
        
        return helper(0,0);
    
    }
};