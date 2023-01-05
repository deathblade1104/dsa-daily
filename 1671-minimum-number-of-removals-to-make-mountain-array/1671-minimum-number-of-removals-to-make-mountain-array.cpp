class Solution {
public:
    
    int dp1[1001],dp2[1001];
    int minimumMountainRemovals(vector<int>& nums) {
        
        memset(dp1,-1,sizeof dp1);
	    memset(dp2,-1,sizeof dp2);
	    
	    
	    for(int i=0;i<nums.size();i++){
	        
	        int ans = 0;
	        for(int j=0;j<i;j++){
	            if(nums[i]>nums[j]){
	                ans = max(ans,dp1[j]);
	            }
	        }
	        
	        dp1[i] = ans + 1;
	    }
	    
	    
	    for(int i=nums.size()-1;i>=0;i--){
	        
	        int ans = 0;
	        for(int j=nums.size()-1;j>i;j--){
	            if(nums[i]>nums[j]){
	                ans = max(ans,dp2[j]);
	            }
	        }
	        
	        dp2[i] = ans + 1;
	    }
	    
	    int n=nums.size(),ans =0;
	    
	    for(int i=0;i<n;i++){
	        
            if(dp1[i]>1 and dp2[i]>1)
	        ans = max(ans,dp1[i] + dp2[i] - 1);
	    }
	    
	    return n-ans;
    }
};