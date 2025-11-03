class Solution {
    private int n;
    private int[][] dp, palinDp;

    // Function to check if the substring s[i:j+1] is a palindrome
    private int isPalin(int i, int j, String s) {
        if (i > j)
            return palinDp[i][j] = 1;  // An empty string is considered a palindrome
        if (i == j)
            return palinDp[i][j] = 1;  // A single character is a palindrome

        if (palinDp[i][j] != -1)
            return palinDp[i][j];

        if (s.charAt(i) != s.charAt(j)) {
            return palinDp[i][j] = 0;
        }

        return palinDp[i][j] = isPalin(i + 1, j - 1, s);  // Check the inner substring
    }

    // Helper function to compute the length of the longest palindromic substring
    private int helper(int i, int j, String s) {
        if (i > j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;
        if (isPalin(i, j, s) == 1)
            ans = j - i + 1;

        helper(i + 1, j, s);
        helper(i, j - 1, s);

        return dp[i][j] = ans;
    }

    public String longestPalindrome(String s) {
        n = s.length();
        dp = new int[n][n];
        palinDp = new int[n][n];

        // Initialize dp and palinDp arrays
        for (int i = 0; i < n; i++) {
            Arrays.fill(dp[i], -1);
            Arrays.fill(palinDp[i], -1);
        }

        helper(0, n - 1, s);

        int maxLen = 1, start = 0, end = 0;

        // Find the maximum length of the palindromic substring
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isPalin(i, j, s) == 1 && j - i + 1 > maxLen) {
                    start = i;
                    end = j;
                    maxLen = j - i + 1;
                }
            }
        }

        // Corrected substring method call
        return s.substring(start, end + 1);
    }
}
