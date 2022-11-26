class Solution {
public:
    int dp[1001];
    int findLongestChain(vector<vector<int>>& pairs) {
    
        sort(pairs.begin(),pairs.end());
        memset(dp,0,sizeof dp);
        int ans =0;
        
        for(int i=0;i<pairs.size();i++){
            for(int j=0;j<i;j++){
                
                if(pairs[j][1]<pairs[i][0])
                    dp[i] = max(dp[i],dp[j]);
                
            }
            dp[i]++;
            ans = max(ans,dp[i]);
        }
        
        return ans;
        
    }
};