class Solution {
    public int pivotIndex(int[] nums) {
        int n = nums.length;
        int totalSum = 0;
        int leftSum = 0;

        for(int i=0; i<n; i++){
            totalSum += nums[i];
        }

        for(int j=0; j<n; j++ ){
            int rightSum = totalSum-leftSum-nums[j];

            if(leftSum == rightSum ) return j;

            leftSum += nums[j];

        }
        
        return -1;
        
    }
}