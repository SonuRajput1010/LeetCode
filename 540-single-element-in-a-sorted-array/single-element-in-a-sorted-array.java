class Solution {
    public int singleNonDuplicate(int[] nums) {
        int n = nums.length;
        int l = 0;
        int r = n-1;

        while(l<r){
            int mid = l + (r-l)/2;
            boolean isEven;
            if(mid % 2 == 0) isEven = true;
            else isEven = false;

            if(nums[mid] == nums[mid+1]){
                if(isEven){
                    l = mid + 2;
                }
                else{
                    r = mid-1;
                }
            }
            else { //nums[mid] != nums[mid+1]
                if(isEven){
                    r = mid;
                }
                else{
                    l = mid+1;
                }
            }
        }

        return nums[r];
    }
}