class Solution {
public:
    int gcdMemo[14][14] = {};
    int memo[1 << 14] = {};
    int m, n;
    int maxScore(vector<int>& nums) {
        m = nums.size(), n = m / 2;
        return dp(nums, 1, 0);
    }
    int dp(vector<int>& nums, int op, int mask) {
        if (op > n) return 0; // Reach to n operations
        if (memo[mask] != 0) return memo[mask];

        for (int i = 0; i < m; ++i) {
            if ((mask >> i) & 1) continue; // If nums[i] is used -> Skip
            for (int j = i + 1; j < m; ++j) {
                if ((mask >> j) & 1) continue; // If nums[i] is used -> Skip
                int newMask = (1 << i) | (1 << j) | mask; // Mark nums[i] and nums[i] as used!
                int score = op * gcd(nums, i, j) + dp(nums, op + 1, newMask);
                memo[mask] = max(memo[mask], score);
            }
        }
        return memo[mask];
    }
    int gcd(vector<int>& nums, int i, int j) { // gcd with cache
        if (gcdMemo[i][j] != 0) return gcdMemo[i][j];
        return gcdMemo[i][j] = __gcd(nums[i], nums[j]);
    }
};