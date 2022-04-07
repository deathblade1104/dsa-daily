class Solution {
public:
    int dp[1001];
    int get_ans(int curr, int&target, vector<int>&nums)
    {
        if(curr==target)
            return 1;
        
        if(dp[curr]!=-1)
            return dp[curr];
        
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
 
            if(nums[i]+curr<=target)
                ans += get_ans(curr+nums[i],target,nums);
            
            if(nums[i]+curr>target)
                break;
        }
        
        return dp[curr]= ans;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
       sort(nums.begin(),nums.end());
        memset(dp,-1,sizeof(dp));
        
        int ans= get_ans(0,target,nums);        
        return ans;
    }
};