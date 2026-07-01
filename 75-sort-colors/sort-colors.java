class Solution {
    public void sortColors(int[] nums) {
        int n = nums.length-1;

        int l =0;
        int m = 0;
        int h = n;

        while( m<=h){
            if(nums[m] == 0){
                nums[m] = nums[l];
                nums[l] = 0;
                m++;
                l++;
            }
            else if(nums[m] == 1) m++;
            else{
                nums[m] = nums[h];
                nums[h] = 2;
                h--;
            }
        }
        
    }
}