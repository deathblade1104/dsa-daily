class Solution {
public:
    long long numberOfWays(string s) {
      long long dp[4][2] = {};
        dp[0][0] = dp[0][1] = 1;
        for (int i = 0; i < s.size(); ++i) {
            for (int len = 1; len <= 3; ++len) {
                dp[len][s[i] - '0'] += dp[len - 1][1 - (s[i] - '0')];
            }
        }
        return dp[3][0] + dp[3][1];
        
    }
};