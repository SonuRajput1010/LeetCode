class Solution {
    public int findPivot(int[] nums){
        int n = nums.length;
        int l=0;
        int r = n-1;

        while(l<r){
            int mid = l + (r-l)/2;

            if(nums[mid] > nums[r]){
                l = mid + 1;
            }
            else{
                r = mid;
            }
        }
         return r;
    }

    public int binarySearch(int[] nums, int l, int r, int target){

        while(l<=r){
            int mid = l + (r-l)/2;

            if(nums[mid] < target ){
                l = mid+1;
            }
            else if(nums[mid] > target ){
                r = mid-1;
            }
            else{
                return mid;
            }
        }
        return -1;
    }
    public int search(int[] nums, int target) {
        
        int n= nums.length;

        int l=0;
        int r=n-1;

        int pivot = findPivot(nums);

        int idx = binarySearch(nums , 0, pivot-1,target);

        if(idx != -1) return idx;

        idx = binarySearch(nums,pivot,n-1,target);
        return idx;

    }
}