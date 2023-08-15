class Solution {
public:
    int dp[71][4901];
    
    int n,m,tar;
    
    int helper(int r,int currSum,vector<vector<int>>&mat){
        
        if(r>=n)
            return abs(currSum - tar);
        
        if(dp[r][currSum]!=-1)
            return dp[r][currSum];
        
        
        int ans = INT_MAX;
        
        for(int i=0;i<m;i++){
            ans = min(ans,helper(r+1,currSum+mat[r][i],mat));
        }
        
        return dp[r][currSum] = ans;
        
    }
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        memset(dp,-1,sizeof dp);
        n = mat.size();
        m = mat[0].size();
        tar = target;
        
        return helper(0,0,mat);
    
    }
};