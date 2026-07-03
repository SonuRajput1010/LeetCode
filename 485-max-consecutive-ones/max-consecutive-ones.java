class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int n = nums.length;
        int cnt = 0;
        int maxCnt = 0;

        int i = 0;
        int j=0;

        while(j<n){
            if(nums[j] == 1){
                cnt++;
                maxCnt = Math.max(cnt,maxCnt);
            }
            else{
                cnt = 0;
                i = j+1;
            }
            j++;
        } 
        return maxCnt;
    }
}