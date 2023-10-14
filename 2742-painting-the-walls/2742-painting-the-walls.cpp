class Solution {
public:
    int dp[501][501];
    int n;
    int helper(int curr, int rem, vector<int>&c, vector<int>&t){
        
        if(rem<=0) return 0;
        
        if(curr>=n)
             return 1e9;
        
        if(dp[curr][rem]!=-1)
            return dp[curr][rem];
        
        int op1 = helper(curr+1,rem,c,t);
        int op2 = c[curr] + helper(curr+1,rem - t[curr] - 1,c,t);
        
        return dp[curr][rem] =  min(op1,op2);
        
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        memset(dp,-1,sizeof dp);
        n = cost.size();
        
        return helper(0,n,cost,time);
        
      
    }
};