class Solution {

    // Reverse subarray from start to end (inclusive)
    void reverseArray(int[] nums, int start, int end) {
        while (start < end) {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }

    public void rotate(int[] nums, int k) {
        int n = nums.length;
        k = k % n; 
        if (k == 0) return;

        reverseArray(nums, 0, n - k - 1);

        reverseArray(nums, n - k, n - 1);

        reverseArray(nums, 0, n - 1);
    }
}
