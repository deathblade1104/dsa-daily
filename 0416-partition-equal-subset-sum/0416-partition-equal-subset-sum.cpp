class Solution {
public:
    int dp[201][20001];
    
    bool get_ans(int curr, int target, vector<int>&nums)
    {
        if(target==0) return true;
        
        if(curr>=nums.size())
            return false;
        
        if(dp[curr][target]!=-1)
            return dp[curr][target];
        
        bool op1 = false;
        
        if(nums[curr]<=target)
        op1 =get_ans(curr+1, target - nums[curr], nums);
        
        if(op1)
            return dp[curr][target] = true;
            
        bool op2 = get_ans(curr+1, target, nums);
        
        return dp[curr][target] = op1 | op2;
    }
    bool canPartition(vector<int>& nums) {
        memset(dp,-1,sizeof dp);
        int sum=0;
        
        for(int i : nums)
            sum+=i;
        
        if(sum%2!=0)
            return false;
        
        sort(nums.begin(),nums.end());
        return get_ans(0,sum/2,nums);
        
    }
};