class Solution {
public:
    int f(int i, string &s, bool bSeen, vector<vector<int>>& dp) {
        // Base case: If we reach the end of the string, no further deletions are needed
        if (i == s.size()) {
            return 0;
        }
        // If already computed, return the stored result
        if (dp[i][bSeen] != -1) {
            return dp[i][bSeen];
        }

        int take = 1e9, notTake = 1e9;

        // If the current character is 'a'
        if (s[i] == 'a') {
            if (bSeen) {
                // We have already seen a 'b', so we must delete this 'a'
                notTake = 1 + f(i + 1, s, bSeen, dp);
            } else {
                // We have not seen a 'b', so we can keep this 'a'
                take = f(i + 1, s, bSeen, dp);
            }
        } else {
            // If the current character is 'b'
            if (bSeen) {
                // We have already seen a 'b', so we can keep this 'b'
                take = f(i + 1, s, bSeen, dp);
            } else {
                // We have not seen a 'b', so we can either keep this 'b' or delete it
                take = f(i + 1, s, true, dp);  // Mark b as seen
                notTake = 1 + f(i + 1, s, bSeen, dp);  // Delete the 'b'
            }
        }

        // Store the result in dp array and return the minimum deletions
        return dp[i][bSeen] = min(take, notTake);
    }

    int minimumDeletions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));  // Initialize 2D dp array with -1
        return f(0, s, false, dp);  // Start the recursive function from the first character with bSeen as false initially
    }
};
