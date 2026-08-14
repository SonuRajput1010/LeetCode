class Solution {
    public int lowerBound(int[] nums, int target){
        int n = nums.length;
        int l= 0;
        int r = n-1;
        int ans = -1;

        int mid = l + (r-l)/2;

        while(l<=r){
            mid = l + (r-l)/2;

            if(nums[mid] >= target){
                ans = mid;
                r = mid-1;
            }
            else {
                l = mid+1;
            }
        }
        return ans;
    }

    public int upperBound(int[] nums, int target){
        int n = nums.length;
        int l= 0;
        int r = n-1;
        int ans = -1;

         int mid = l + (r-l)/2;

        while(l<=r){
            mid = l + (r-l)/2;

            if(nums[mid] <= target){
                ans = mid;
                l = mid+1;
            }
            else {
               r=mid-1;
            }
        }
        return ans;
    }

    public int[] searchRange(int[] nums, int target) {

        int leftMost = lowerBound(nums,target);
        int rightMost = upperBound(nums,target);
        
        if(leftMost == -1 || nums[leftMost] != target ) return new int[]{-1,-1};

        return new int[]{leftMost,rightMost};
        
    }
}