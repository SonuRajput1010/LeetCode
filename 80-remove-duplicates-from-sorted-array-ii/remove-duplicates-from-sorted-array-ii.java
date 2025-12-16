class Solution {
    public int removeDuplicates(int[] nums) {
        int n = nums.length;
        int a=2;
        if(n < 3){
            return n;
        }

        for(int i=2; i<n; i++){
            if(nums[i] != nums[a-2]){
                nums[a] = nums[i];
                a++;
            }
        }
        return a;
    }
}