class Solution {
    public int numOfWays(int n) {
        long MOD = 1_000_000_007L;

        long a = 6; // all 3 different
        long b = 6; // 2 colors pattern

        for (int i = 2; i <= n; i++) {
            long newA = (2 * a + 2 * b) % MOD;
            long newB = (2 * a + 3 * b) % MOD;

            a = newA;
            b = newB;
        }

        return (int)((a + b) % MOD);
    }
}
