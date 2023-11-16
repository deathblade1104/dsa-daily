class Solution {
public:
    int n,finalState;
    int dp[16385];
    
    int helper(int mask,vector<int>& nums1, vector<int>& nums2){
        int curr  = __builtin_popcount(mask);
        
        if(mask>=finalState or curr>=n)
            return 0;
        
        if(dp[mask]!=-1)
             return dp[mask];
        
        int ans = 1e9;

        for(int i=0;i<n;i++){
            
            if ((mask & (1 << i)) != 0)
                continue;
            
            int currSum = nums1[curr] ^ nums2[i];
            currSum+=helper(mask|(1<<i),nums1,nums2);
            ans = min(ans,currSum);
        }
        return dp[mask]  = ans;
    }
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        n = nums2.size();
        finalState = (1<<n) - 1;
        memset(dp,-1,sizeof dp);
        
        return helper(0,nums1,nums2);
    }
};