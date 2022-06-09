class Solution {
public:
    int dp[1001][2001];    
    int helper(int curr,int k,int&n,vector<vector<int>>&piles)
    {
        if(curr>=n or k==0)
        return 0;
        
        if(dp[curr][k]!=-1)
            return dp[curr][k];
        
        int consider = 0,sz=piles[curr].size();
        for(int i=0;i<min(sz,k);i++)
        {
            int temp  = piles[curr][i] + helper(curr+1,k-i-1,n,piles);
            consider = max(consider,temp);
        }
        
        int dont_consider = helper(curr+1,k,n,piles);
        return dp[curr][k] = max(consider,dont_consider);
    }
    
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        memset(dp,-1,1001*2001*sizeof(int));
        int n = piles.size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<piles[i].size();j++)
                piles[i][j]+=piles[i][j-1];
        }
        
        
        return helper(0,k,n,piles);
    }
};