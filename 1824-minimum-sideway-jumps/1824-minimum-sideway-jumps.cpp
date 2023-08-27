class Solution {
public:
    int n;
    int dp[500001][3];
    int helper(int curr,int lane,vector<int>&arr){
        
        if(curr>=n-1)
            return 0;
        
        if(dp[curr][lane]!=-1)
            return dp[curr][lane];
        
        if(arr[curr+1] != lane+1)
            return dp[curr][lane] = helper(curr+1, lane,arr);
      
        int ans = 10e5;
        
        for(int i = 0 ; i < 3 ; i++)
        {
            if(i == lane || arr[curr] == i+1)
                continue;
            ans = min(ans, helper(curr, i,arr));
            if(ans == 0)
                break;
        }
        
        return dp[curr][lane] = 1 + ans;
    }
    
    int minSideJumps(vector<int>& obstacles) {
        n = obstacles.size();   
        memset(dp,-1,sizeof dp);
        
        return helper(0,1,obstacles);
    }
};