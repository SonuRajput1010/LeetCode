class Solution {
    public int searchLeft(int[] nums, int target){
        int l=0;
        int r=nums.length-1;
        int leftMost = -1;
     
        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid]  == target){
                leftMost = mid;
                r = mid-1;
            }
            else if(nums[mid] < target){
                l = mid+1;
            }
            else 
                r = mid-1;
        }
        return leftMost;
    }
    public int searchRight(int[] nums, int target){
        int l=0;
        int r=nums.length-1;
        int rightMost = -1;

        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target){
                rightMost = mid;
                l = mid+1;

            }
            else if(nums[mid] < target){
                l = mid+1;
            }
            else 
                r = mid-1;
        }
        return rightMost;
    }
    public int[] searchRange(int[] nums, int target) {
        int l=0;
        int r=nums.length-1;
        
        int leftMost = searchLeft(nums,target);
        int rightMost = searchRight(nums,target);
        

        return new int[]{leftMost,rightMost};
    }
}