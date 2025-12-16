class Solution {
    private static final int MOD = 1_000_000_007;

    // Returns pair: {F(n), F(n+1)}
    static int[] fibPair(int n) {
        if (n == 0) {
            return new int[]{0, 1};
        }

        int[] p = fibPair(n / 2);
        long a = p[0]; // F(k)
        long b = p[1]; // F(k+1)

        // Fast doubling formulas
        long c = (a * ((2 * b % MOD - a + MOD) % MOD)) % MOD; // F(2k)
        long d = (a * a % MOD + b * b % MOD) % MOD;           // F(2k+1)

        if (n % 2 == 0) {
            return new int[]{(int) c, (int) d};
        } else {
            return new int[]{(int) d, (int) ((c + d) % MOD)};
        }
    }

    public int fib(int n) {
        return fibPair(n)[0]; // return F(n)
    }
}
