class Solution {
public:
    static const int mod = 1e9+ 7;
    int n,k;
    long long int dp[101][101][101];
    
    long long int binaryExp(int pow){
        if(pow == 0)
            return 1LL;
        
        if(pow == 1)
            return 1LL * 2; 
        
        long long  int ans = binaryExp(pow/2)%mod ;
        ans = ((ans%mod) * (ans%mod))%mod;
        
        if(pow&1)
            ans = ((ans%mod) * 2)%mod;
        
        return ans;
    }
    
    long long int helper(int idx,int currSum,int len,vector<int>&nums){
        
        if(currSum == 0){
            return binaryExp(n - len);
        }
        
        if(idx>=n)
            return 0;
        
        long long int &ans = dp[idx][currSum][len];
        
        if(ans!=-1)
            return ans;
        
        ans = 0;
        
        if(nums[idx]<=currSum)
            ans = helper(idx+1,currSum-nums[idx],len+1,nums);
        
        ans = (ans%mod + helper(idx+1,currSum,len,nums)%mod)%mod;
        
        return ans;
    
    }
    
    int sumOfPower(vector<int>& nums, int k) {
        n = nums.size();
        this->k = k; 
        memset(dp,-1,sizeof dp);
        
        return helper(0,k,0,nums);
    }
};