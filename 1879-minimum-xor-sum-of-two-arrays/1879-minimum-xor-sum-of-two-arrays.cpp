class Solution {
public:
    int n,finalState;
    int dp[15][16385];
    int helper(int curr, int mask,vector<int>& nums1, vector<int>& nums2){
        
        if(mask>=finalState or curr>=n)
            return 0;
        
        if(dp[curr][mask]!=-1)
             return dp[curr][mask];
        
        int ans = 1e9;

        for(int i=0;i<n;i++){
            
            if ((mask & (1 << i)) != 0)
                continue;
            
            int currSum = nums1[curr] ^ nums2[i];
            currSum+=helper(curr+1,mask|(1<<i),nums1,nums2);
            ans = min(ans,currSum);
        }
        return dp[curr][mask]  = ans;
    }
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        n = nums2.size();
        finalState = (1<<n) - 1;
        memset(dp,-1,sizeof dp);
        
        return helper(0,0,nums1,nums2);
    }
};