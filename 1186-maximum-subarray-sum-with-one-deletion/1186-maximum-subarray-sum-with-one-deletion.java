class Solution {
    private int n;
    private int[][] dp;
    
    private int helper(int curr, int deleted, int[] arr) {
        if (curr >= n)
            return Integer.MIN_VALUE/2;
        
        if (dp[curr][deleted] != -1)
            return dp[curr][deleted];
        
        // Case 1: Take the current element and continue
        int take = arr[curr] + helper(curr + 1, deleted, arr);
        
        // Case 2: Delete the current element (if not deleted yet)
        int notTake = deleted == 0 ? helper(curr + 1, 1, arr) : Integer.MIN_VALUE/2;
        
        // Case 3: Start a new subarray (consider the current element as a new start)
        int newStart = arr[curr];

        // Find the maximum result
        int result = Math.max(Math.max(take, notTake), newStart);
        
        return dp[curr][deleted] = result;
    }

    public int maximumSum(int[] arr) {
        n = arr.length;
        dp = new int[n][2];
        
        for (int i = 0; i < n; i++)
            Arrays.fill(dp[i], -1);
        
        int maxSum = Integer.MIN_VALUE;
        for (int i = 0; i < n; i++) {
            maxSum = Math.max(maxSum, helper(i, 0, arr));
        }
        
        return maxSum;
    }
}
