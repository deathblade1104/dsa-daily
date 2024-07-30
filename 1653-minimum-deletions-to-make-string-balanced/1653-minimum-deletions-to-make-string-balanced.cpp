class Solution {
public:
    int f(int i, string &s, bool a, vector<vector<int>>& dp) {
        // Base case: If index is out of bounds, no deletions are needed
        if (i < 0) {
            return 0;
        }
        // If already computed, return the stored result
        if (dp[i][a] != -1) {
            return dp[i][a];
        }
        // Initialize the deletion counts
        int take = 1e9, notTake = 1e9;
        
        // If the current character is 'b'
        if (s[i] == 'b') {
            // If no 'a' has been encountered, no deletion needed for 'b'
            if (!a) {
                take = f(i - 1, s, a, dp);  // Keep the 'b'
            } else {
                // Otherwise, delete the current 'b'
                notTake = 1 + f(i - 1, s, a, dp);  // Delete the 'b'
            }
        } else {
            // If the current character is 'a'
            // Keep the 'a' and set 'a' to true
            take = f(i - 1, s, true, dp);  // Keep the 'a' and mark 'a' as found
            // Or delete the 'a'
            notTake = 1 + f(i - 1, s, a, dp);  // Delete the 'a'
        }

        // Store the result in dp array and return the minimum deletions
        return dp[i][a] = min(take, notTake);
    }

    int minimumDeletions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));  // Initialize 2D dp array with -1
        return f(n - 1, s, false, dp);  // Start the recursive function from the last character with 'a' being false initially
    }
};
