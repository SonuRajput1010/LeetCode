class Solution {
    public int repeatedNTimes(int[] nums) {

        for(int i=0; i<nums.length; i++){
            if(i+1 <nums.length && nums[i] == nums[i+1]) return nums[i];

            if(i+2 < nums.length && nums[i] == nums[i+2]) return nums[i];
        }
        return nums[nums.length - 1];
    }
}