class Solution {
public:
    int dp[301][1001][11];
    int helper(int curr,int prev, int day, vector<int>&nums){
        
        if(day<0)
            return INT_MAX/2;
        
        if(curr == nums.size())
            return day==0 ? prev : INT_MAX/2;
        
        if(dp[curr][prev][day]!=-1)
            return dp[curr][prev][day];
        
        int take = prev + helper(curr+1,nums[curr],day-1,nums);
        int dontTake = helper(curr+1,max(prev,nums[curr]),day,nums);
        
        return dp[curr][prev][day] = min(take,dontTake);
        
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        
        if(d>jobDifficulty.size())
            return -1;
        
        memset(dp,-1,sizeof dp);
        
        return helper(0,0,d,jobDifficulty);
    }
};