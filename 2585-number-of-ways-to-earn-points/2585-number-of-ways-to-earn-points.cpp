class Solution {
public:
    static const int mod = 1e9 +7;
    int dp[1001][51][51][2];
    int n;
    
    int helper(int target,int currIdx,int currCount,bool started,vector<vector<int>>& types){
        
        if(target == 0)
            return 1;
        
        if(currIdx>=n)
            return 0;
        
        int &ans = dp[target][currIdx][currCount][started];
        
        if(ans!=-1)
            return ans;
        
        ans = helper(target,currIdx+1,0,0,types);
        
        if(!started)
            currCount = types[currIdx][0];
        
    
        if(currCount>0 and types[currIdx][1]<=target)
            ans = (ans%mod + helper(target-types[currIdx][1],currIdx,currCount-1,1,types)%mod)%mod;
        
        return ans;   
    }
    
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        memset(dp,-1,sizeof dp);
        n = types.size();
        return helper(target,0,0,0,types);
    }
};