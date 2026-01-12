class Solution {
    public int reverse(int x) {
        int n = x;
        int num = 0;
        
        while( n != 0){
            int digit = n%10;

            // Positive overflow
            if(num > Integer.MAX_VALUE/10 || 
            (num == Integer.MAX_VALUE/10 && digit > 7)) return 0;
            // negative overflow
            if(num < Integer.MIN_VALUE/10 || 
            (num == Integer.MIN_VALUE/10 && digit < -8)) return 0;

            num = num * 10 + digit;
            n = n / 10;
        }
        return num;
    }
}