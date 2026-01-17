class Solution {
    int findPivot(int[]nums, int l, int r) {
        while (l < r) {

            while (l < r && nums[l] == nums[l + 1]) 
                l++;

            while (l < r && nums[r] == nums[r - 1]) 
                r--;

            int mid = l + (r - l) / 2;

            if (nums[mid] > nums[r]) {
                l = mid + 1;
            } else {
                r = mid; 
            }
        }
        return r;
    }

    public boolean binarySearch(int[] nums, int l, int r, int target){

        while(l<=r){
            int mid = l + (r-l)/2;

            if(nums[mid] < target ){
                l = mid+1;
            }
            else if(nums[mid] > target ){
                r = mid-1;
            }
            else{
                return true;
            }
        }
        return false;
    }
    public boolean search(int[] nums, int target) {
        
        int n= nums.length;

        int l=0;
        int r=n-1;

        int pivot = findPivot(nums,0,n-1);
        boolean left = binarySearch(nums , 0, pivot-1,target);
        boolean right = binarySearch(nums,pivot,n-1,target);
        
        return left || right;

    }
}