class Solution {
public:
    int dp[100001];
    int helper(int curr,int n,vector<int>&nums){
                
        if(curr >= n-1)
            return  0;
        
        if(dp[curr]!=-1)
            return dp[curr];
        
        
        int steps = 10002;
        for(int i=1;i<=nums[curr];i++){
        
            int temp = 1 + helper(curr+i,n,nums);
            steps = min(steps,temp);
        }
        
        return dp[curr] = steps;
    }
    
    int jump(vector<int>& nums) {
        
        memset(dp,-1,sizeof dp);
        int n = nums.size();
        return helper(0,n,nums);
        
    }
};