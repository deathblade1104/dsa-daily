class Solution {
   private static final int MOD = 1_000_000_007;

    // returns {F(n), F(n+1)}
    private long[] fib(long n) {
        if (n == 0) return new long[]{0, 1};

        long[] p = fib(n / 2);
        long a = p[0], b = p[1];

        long c = a * (2 * b - a);
        long d = a * a + b * b;

        if (n % 2 == 0)
            return new long[]{c, d};
        else
            return new long[]{d, c + d};
    }

    public int climbStairs(int n) {
        // ways(n) = F(n+1)
        return (int) fib(n + 1)[0];
    }
}