class Solution {
public:
    int dp[201][20001];
    
    bool get_ans(int curr, int val, int target, vector<int>&nums)
    {
        if(target==val) return true;
        
        if(curr>=nums.size())
            return false;
        
        if(dp[curr][val]!=-1)
            return dp[curr][val];
        
        bool op1 = get_ans(curr+1, val+nums[curr],target, nums);
        
        if(op1)
            return dp[curr][val] = true;
            
        bool op2 = get_ans(curr+1, val,target, nums);
        
        return dp[curr][val] = op1 | op2;
    }
    bool canPartition(vector<int>& nums) {
        memset(dp,-1,201*20001*sizeof(int));
        int sum=0;
        
        for(int i : nums)
            sum+=i;
        
        if(sum%2!=0)
            return false;
        
        else
            return get_ans(0,0,sum/2,nums);
        
    }
};