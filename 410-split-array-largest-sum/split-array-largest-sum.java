class Solution {
    public int canPaint(int[]nums, long mid){
        long noOfPainter = 1;
        long wallPaint = 0;

        for(int i=0; i<nums.length; i++){
            if(wallPaint + nums[i] <= mid) wallPaint += nums[i];
            else {
                wallPaint = nums[i];
                noOfPainter++;
            }
        }
        return (int)noOfPainter;
    }

    public int splitArray(int[] nums, int k) {
        int n = nums.length;
        if(n < k) return -1;

        long low = Integer.MIN_VALUE;
        long high = 0;

        for(int x : nums){
            low = Math.max(low,x);
            high += x;
        } 

        while(low <= high){
            long mid = low + (high-low)/2;

            int Painter = canPaint(nums, mid);

            if(Painter > k) low = mid+1;
            else high = mid-1;
        }
        return (int)low;
    }
}