class Solution {
public:
    map<array<int,3>,int>dp;
    
    int helper(int i,int j,bool prev,vector<int>&nums1,vector<int>&nums2){
        
        if(i>=nums1.size() or j>=nums2.size())
            return prev == false ? INT_MIN/2 : 0;
        
        array<int,3>curr = {i,j,prev};
        
        if(dp.count(curr))
            return dp[curr];
        
        int select =(nums1[i] * nums2[j]) + helper(i+1,j+1,prev|true,nums1,nums2);
        
        int dontSelect = max(helper(i,j+1,prev|false,nums1,nums2), helper(i+1,j,prev|false,nums1,nums2));
        
        return dp[curr] = max(select,dontSelect);
    }
    
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        
        dp.clear();
        return helper(0,0,0,nums1,nums2);
    }
};