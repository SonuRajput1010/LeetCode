class Solution {
    public long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {

        long ans = Long.MAX_VALUE;

        int[] cand = {
            0,
            Math.min(need1, need2),
            Math.max(need1, need2)
        };

        for (int x : cand) {
            if (x < 0) continue;

            long rem1 = Math.max(0, need1 - x);
            long rem2 = Math.max(0, need2 - x);

            long cost = 0;

            cost += (long)x * costBoth;

            cost += Math.min(rem1 * (long)cost1, rem1 * (long)costBoth);
            cost += Math.min(rem2 * (long)cost2, rem2 * (long)costBoth);

            ans = Math.min(ans, cost);
        }

        return ans;
    }
}
