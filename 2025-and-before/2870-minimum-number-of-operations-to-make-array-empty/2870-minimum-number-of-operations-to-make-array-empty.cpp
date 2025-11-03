class Solution {
public:
    int n;
    static const int maxN = 1e5+1;
    int dp[maxN];
    
    int helper(int curr,vector<int>&arr){
    
        if(curr>=n)
            return 0;
        
        int &ans = dp[curr];
        
        if(ans!=-1)
            return ans;
        
        ans = INT_MAX/2;
        
        if(curr<=n-2 and arr[curr]==arr[curr+1])
            ans = min(ans, 1 + helper(curr+2,arr));
        
        if(curr<=n-3 and arr[curr]==arr[curr+1] and arr[curr+1]==arr[curr+2])
            ans = min(ans, 1 + helper(curr+3,arr));
        
        return ans;
    }
    
    int minOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        n = nums.size();
        
        memset(dp,-1,sizeof dp);
        
        int ans =  helper(0,nums);
        
        if(ans>=INT_MAX/2)
            return -1;
        
        return ans;
        
    }
};