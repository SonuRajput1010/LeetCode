class Solution {
    public boolean isPalindrome(int x) {

        if( x < 0) return false;
        int n = x;
        int num = 0;

        while(n != 0){
            int digit = n % 10;
            num = num * 10 + digit;
            n = n/10;
        }

        return num == x;
    }
}