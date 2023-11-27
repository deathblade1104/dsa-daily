class Solution {
public:
    const array<array<int, 2>, 8> dir = {{
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
        {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
    }};
    int n;
    int dp[5000][4][3];
    
    static const int mod = 1e9 + 7;

    bool isValid(int r, int c) {
        if (r < 0 or c < 0 or r >= 4 or c >= 3)
            return false;

        if (r == 3 and (c == 0 || c == 2))
            return false;

        return true;
    }

    int helper(int curr, int r, int c) {
        if (!isValid(r, c))
            return 0;

        if (curr == n - 1)
            return 1;
        
        int &ans = dp[curr][r][c];
        if (ans != -1)
            return ans;

        ans = 0;

        for (int i = 0; i < 8; i++) {
    
            int x = r + dir[i][0], y = c + dir[i][1];
            ans =(ans%mod + helper(curr + 1, x, y)%mod)%mod;
            
        }

        return ans;
    }

    int knightDialer(int N) {
        int ans = 0;
        n = N;
        memset(dp,-1,sizeof dp);
        
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                if (isValid(i, j))
                    ans = (ans%mod + helper(0, i, j)%mod)%mod;
            }
        }
    
        return ans; 
    }
};
