class Solution {
public:
    
    int dp[1001];
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        memset(dp,-1,sizeof dp);
        vector<array<int,2>>v;
        int n = ages.size();
        for(int i=0;i<n;i++)
            v.push_back({ages[i],scores[i]});
        
        sort(v.begin(),v.end());
        int ans = 0;
        for(int i=0;i<n;i++){
            dp[i] = v[i][1];
            for(int j=0;j<i;j++){
                if(v[j][1]<=v[i][1]){
                    dp[i] = max(dp[i],dp[j] + v[i][1]);
                }
            }
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
};