class Solution {
public:
    int dp[201][10001];
    
    bool helper(int curr, int  target,vector<int>&arr){
        
        if(target==0)
            return true;
        
        if(curr<0)
            return false;
        
        if(dp[curr][target]!=-1)
            return dp[curr][target];
        
        bool op1 = false;
        if(arr[curr]<=target){
            op1 = helper(curr-1,target-arr[curr],arr);
        }
        
        if(op1)
            return dp[curr][target] = true;
        
        return dp[curr][target] = helper(curr-1,target,arr);
    }
    
    bool canPartition(vector<int>& nums) {
        int sum  = 0;
        
        for(int&i : nums)
            sum+=i;
        
        if(sum&1)
            return false;
        
        sort(nums.begin(),nums.end());
        memset(dp,-1,sizeof dp);
        int sz = nums.size();
        sum/=2;
        
        return helper(sz-1,sum,nums);
        
    }
};