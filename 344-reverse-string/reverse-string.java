class Solution {
    public void swap(char[] nums, int i, int j){
        char temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    public void reverseString(char[] s) {
        int l=0;
        int r= s.length-1;
        while(l<=r){
            swap(s,l,r);
            l++;
            r--;
        }
    }
}