class Solution {
public:
    int dp[71][5001];
    int helper(int r,int&n,int&m,vector<vector<int>>&mat,int&target,int prev){
       
        if(r>=n)
            return abs(target - prev);
        if(dp[r][prev]!=-1)
            return dp[r][prev];
        
        int ans = INT_MAX/2;
        for(int i=0;i<m and ans!=0;i++){
            ans = min(ans,helper(r+1,n,m,mat,target,prev+mat[r][i]));
        }
        
        return dp[r][prev] = ans;
    }
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        
        memset(dp,-1,sizeof dp);
        int n = mat.size(),m= mat[0].size(),curr=0,ans=INT_MAX;
        
        return helper(0,n,m,mat,target,0);
        
    }
};