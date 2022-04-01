class Solution {
public:
    int dp[31][1001];
    int mod = 1000000007;
    int get_ans(int dice, int target,int &k)
    {
        if(dice==0)
        {
            if(target==0) return 1;
            else return 0;
        }
        
        if(dp[dice][target]!=-1)
            return dp[dice][target];
        
        int ans=0;        
        for(int i=1;i<=min(k,target);i++)
        ans=(ans%mod + get_ans(dice-1,target-i,k)%mod)%mod;        
        
        return dp[dice][target]=ans;
        
    }
    int numRollsToTarget(int n, int k, int target) {
        memset(dp,-1,31*1001*sizeof(int));
        return get_ans(n,target,k);
    }
};