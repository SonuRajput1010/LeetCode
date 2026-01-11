class Solution {
    public void swap(int[] nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    public int[] sortArrayByParity(int[] nums) {
        int n = nums.length;
        // int[] ans = new int[n];
        int j=0;
        for(int i=0; i<n; i++){
            if(nums[i] % 2 == 0){
                swap(nums,i,j);
                j++;
            }
        }
        return nums;
    }
}