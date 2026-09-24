class Solution {
    int DigitSum(int n){
        int ans = 0;
        while(n>0){
            int digit = n%10;
            n /= 10;
            ans += digit;
        }
        return ans;
    }
    public int smallestIndex(int[] nums) {
        for(int i=0; i<nums.length; i++){
            if(i == DigitSum(nums[i])) return i;
        }
        return -1;
    }
}