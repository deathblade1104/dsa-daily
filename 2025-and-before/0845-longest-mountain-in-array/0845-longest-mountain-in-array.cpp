class Solution {
public:
    
    int dp1[10001],dp2[10001];
    
    void getLongestIncreasingSubarray(vector<int>&nums,int&n){
        
        memset(dp1,0,sizeof dp1);
        
        for(int i=0;i<n;i++){
            int curr = 1;
            int prev = max(0,i-1);
            
            if(nums[prev]<nums[i])
                curr = 1 + dp1[prev];
            
            dp1[i] = curr;
        }
        return;
    }
    
    void getLongestDecreasingSubarray(vector<int>&nums,int&n){
        
        memset(dp2,0,sizeof dp1);
        
        for(int i=n-1;i>=0;i--){
            int curr = 1;
            int prev = min(n-1,i+1);
            
            if(nums[prev]<nums[i])
                curr = 1 + dp2[prev];
            
            dp2[i] = curr;
        }
        return;
    }
    
    int longestMountain(vector<int>& arr) {
        
        int n = arr.size(),ans = 0;
        getLongestIncreasingSubarray(arr,n);
        getLongestDecreasingSubarray(arr,n);
        
        for(int i=0;i<n;i++)
            if(dp1[i]>1 and dp2[i]>1)
                ans = max(ans,dp1[i] + dp2[i] - 1);
        
        return ans;
        
        
    }
};