class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        
        sort(pairs.begin(),pairs.end());
        
        int n = pairs.size();
        vector<int>dp(n,1);
        
        int ans = 1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(pairs[j][1]<pairs[i][0])
                    dp[i] = max(dp[j]+1,dp[i]);
            }
            
            ans= max(dp[i],ans);
        }
        
        return ans;
    }
};