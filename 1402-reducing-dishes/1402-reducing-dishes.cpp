class Solution {
public:
    int dp[501][501];
    int helper(int curr,int t, vector<int>&satisfaction){
        
        if(curr>=satisfaction.size())
            return 0;
        
        if(dp[curr][t]!=-1)
            return dp[curr][t];
        
        int op1 = satisfaction[curr]*(t+1) + helper(curr+1,t+1,satisfaction);
        int op2 = helper(curr+1,t,satisfaction);
        
        return dp[curr][t] = max(op1,op2);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        
        sort(satisfaction.begin(),satisfaction.end());
        memset(dp,-1,sizeof dp);
        
        return helper(0,0,satisfaction);
        
        
    }
};