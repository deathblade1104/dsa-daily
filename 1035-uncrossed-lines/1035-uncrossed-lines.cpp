class Solution {
public:
    
    int dp[501][501];
    int helper(int maxYet,int currIdx, vector<int>&nums1,vector<int>&nums2){
        
        if(currIdx>=nums1.size())
            return 0;
        
        if(dp[maxYet][currIdx]!=-1)
             return dp[maxYet][currIdx];
        
        int ans = helper(maxYet,currIdx+1,nums1,nums2);
        for(int i=maxYet;i<nums2.size();i++){
            if(nums1[currIdx] == nums2[i]){
                //cout<<"Matching :"<<nums1[currIdx]<<" with : "<<nums2[i]<<endl;
                ans = max(ans, 1 + helper(i+1,currIdx+1,nums1,nums2));
            }
        }
        
        return dp[maxYet][currIdx] = ans;
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof dp);
        
        return helper(0,0,nums1,nums2);
    }
};