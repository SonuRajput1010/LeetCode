class Solution {
    public int maxSubArray(int[] nums) {
        
        int sum = 0;
        int large = nums[0];;

        for(int i=0; i<nums.length; i++){
            sum += nums[i];
            large = Math.max(sum,large);

            if(sum < 0) sum = 0;
        }
        return large;
    }
}