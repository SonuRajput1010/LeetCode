class Solution {

    public boolean canEat(int[] piles, int h, int k) {
        long hours = 0;

        for (int p : piles) {
            hours += (p + (long) k - 1) / k;

            if (hours > h) {
                return false;
            }
        }

        return hours <= h;
    }

    public int minEatingSpeed(int[] piles, int h) {

        int low = 1;
        int high = 0;

        for (int p : piles) {
            high = Math.max(high, p);
        }

        int ans = high;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (canEat(piles, h, mid)) {   // ✅ h, NOT high
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
}