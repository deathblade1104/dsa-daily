class Solution {
public:
    int n, m, k;
    vector<vector<vector<int>>> dp;
    static const int mod = (int)1e9 + 7;

    int helper(int r, int c, int currSum, vector<vector<int>>& grid) {
        if (r >= n || c >= m)
            return 0;

        int& ans = dp[r][c][currSum];
        if (ans != -1)
            return ans;

        currSum = (currSum % k + grid[r][c] % k) % k;

        if (r == n - 1 && c == m - 1)
            return ans = currSum == 0 ? 1 : 0;

        ans = helper(r + 1, c, currSum, grid) % mod;
        ans = (ans + helper(r, c + 1, currSum, grid) % mod) % mod;

        return ans;
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        this->k = k;
        dp.assign(n, vector<vector<int>>(m, vector<int>(k, -1)));

        return helper(0, 0, 0, grid);
    }
};
