class Solution {

    public void Swap(char[] nums, int l, int r){
        char temp = nums[l];
        nums[l] = nums[r];
        nums[r] = temp;
    }
    public void reverseString(char[] s) {
        
        int l=0;
        int r = s.length-1;

        while(l<=r){
            Swap(s,l,r);
            l++;
            r--;
        }
    }
}