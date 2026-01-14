class Solution {
    public int majorityElement(int[] nums) {
        int cnt =0;
        int candidate = 0;
        for(int i=0; i<nums.length; i++){
            if(cnt == 0)
                candidate = nums[i];

            if(candidate == nums[i]) cnt++;
            
            else cnt--;
        }
        return candidate;
    }
}