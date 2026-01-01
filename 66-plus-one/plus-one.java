class Solution {
    public int[] plusOne(int[] arr) {
        
        int carry = 1;

        for(int i=arr.length-1; i>=0; i--){
            int sum = arr[i] + carry;
            arr[i] = sum %10;
            carry = sum/10;
        }

        if(carry > 0){
            int[] ans = new int[arr.length+1];
            ans[0] = carry;
            System.arraycopy(arr,0, ans, 1, arr.length);
            return ans;
        }
        return arr;
    }
}