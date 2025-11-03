class Solution {
public:
    int dp[501][501][2];
    
    int helper(int i,int j,bool prev,vector<int>&nums1,vector<int>&nums2){
        
        if(i>=nums1.size() or j>=nums2.size())
            return prev == false ? INT_MIN/2 : 0;
        
        if(dp[i][j][prev]!=INT_MIN)
            return dp[i][j][prev];
        
        int select =(nums1[i] * nums2[j]) + helper(i+1,j+1,prev|true,nums1,nums2);
        
        int dontSelect = max(helper(i,j+1,prev|false,nums1,nums2), helper(i+1,j,prev|false,nums1,nums2));
        
        return dp[i][j][prev] = max(select,dontSelect);
    }
    
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                dp[i][j][0] = dp[i][j][1] = INT_MIN;
            }
        }
        return helper(0,0,0,nums1,nums2);
    }
};