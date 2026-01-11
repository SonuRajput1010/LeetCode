class Solution {
    public int[] sortedSquares(int[] nums) {
        int[] ans = nums.clone();

        for(int i=0; i<nums.length; i++){
            int temp = nums[i];
            ans[i] = temp*temp;
        }
        Arrays.sort(ans);

        return ans;
    }
}