class Solution {
public:
    
    int dp[501][501];
    int helper(int maxYet,int currIdx, vector<int>&nums1,vector<int>&nums2){
        
        if(maxYet>=nums2.size() || currIdx>=nums1.size())
            return 0;
        
        if(dp[maxYet][currIdx]!=-1)
             return dp[maxYet][currIdx];
        
        int ans=0;
        if(nums1[currIdx] == nums2[maxYet]){
            ans = max(ans,1 + helper(maxYet+1,currIdx+1,nums1,nums2));
        }else{
            ans = max(helper(maxYet+1,currIdx,nums1,nums2), helper(maxYet,currIdx+1,nums1,nums2));
        }
        return dp[maxYet][currIdx] = ans;
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof dp);
        
        return helper(0,0,nums1,nums2);
    }
};