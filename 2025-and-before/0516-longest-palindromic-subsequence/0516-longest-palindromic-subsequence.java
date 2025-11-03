class Solution {
    private int n;
    private int[][] dp;
    
    private int helper(int i, int j, String s1, String s2) {
        // Base case: if either string is fully traversed
        if (i >= n || j >= n)
            return 0;

        // Check if result is already computed
        if (dp[i][j] != -1)
            return dp[i][j];

        int op1 = 0, op2 = 0; // op2 should be initialized to 0

        // If characters match, increment result
        if (s1.charAt(i) == s2.charAt(j))
            op1 = 1 + helper(i + 1, j + 1, s1, s2);

        // Either move in s1 or s2
        op2 = Math.max(helper(i + 1, j, s1, s2), helper(i, j + 1, s1, s2));

        // Store and return the maximum of the two operations
        return dp[i][j] = Math.max(op1, op2);
    }

    public int longestPalindromeSubseq(String s) {
        n = s.length(); // Use length() instead of size()
        dp = new int[n][n]; // Allocate dp array with size n x n

        // Reverse the string to compare with original
        StringBuilder sb = new StringBuilder(s);
        String s2 = sb.reverse().toString();

        // Initialize dp array with -1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = -1;
            }
        }

        // Call helper function with original and reversed strings
        return helper(0, 0, s, s2); // Use 's' for the original string
    }
}
