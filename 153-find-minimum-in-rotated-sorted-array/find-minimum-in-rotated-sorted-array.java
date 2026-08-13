class Solution {
    public int findMin(int[] nums) {
        int n = nums.length;
        int l = 0;
        int r = n-1;

        int mini = Integer.MAX_VALUE;


        while(l<=r){
            int mid = mid = l + (r-l)/2;;

            if(nums[mid] < nums[r]){
               r = mid;
            }else{
                l = mid+1;
            }
        }

        return nums[r];
        
    }
}