class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        
        int l = 0;
        int mini = Integer.MAX_VALUE;
        int sum = 0;

        for(int r=0; r<nums.length; r++){
            sum += nums[r];

            while(sum >= target){
                mini = Math.min(mini, r-l+1 );

                sum -= nums[l];
                l++;
            }
        }
        return mini == Integer.MAX_VALUE ? 0 : mini;
    }
}