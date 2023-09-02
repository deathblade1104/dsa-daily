class Solution {
public:
    
    int dp[100001][4];
    int n;
    const int mod = 1e9 +7;
    int helper(int curr,int prevEle,vector<int>&nums){
        
        if(curr>=n)
            return prevEle == 3;
        
        if(dp[curr][prevEle]!=-1)
            return dp[curr][prevEle];
        
         if(nums[curr]<prevEle || (prevEle==1 && nums[curr]==3) || (prevEle==0 && nums[curr]!=1))
            return dp[curr][prevEle] =  helper(curr+1,prevEle,nums) %mod; 
        
        return dp[curr][prevEle] =  (helper(curr+1,prevEle,nums)%mod + helper(curr+1,nums[curr],nums)%mod)%mod; 
    }
    int countSpecialSubsequences(vector<int>& nums) {
        
        for(int&i : nums){
            i++;
        }
        
        n = nums.size();
        memset(dp,-1,sizeof dp);
        
        return helper(0,0,nums);
    }
};