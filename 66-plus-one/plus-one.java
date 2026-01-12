class Solution {
    public int[] plusOne(int[] digits) {

        int n = digits.length;
        int carry = 1;

        for(int i = n-1; i>=0; i--){
            int sum = digits[i] + carry;
            digits[i] = sum%10;
            carry = sum/10;
        }

        if(carry > 0){
            int[] ans = new int[n+1];
            ans[0] = carry;

            for(int i=0; i<n; i++){
                ans[i+1] = digits[i];
            }
            return ans;
        }
        return digits;
    }
}