class Solution {
    public boolean isPalindrome(int x) {
        if (x<0){
           return false;
       }
        int num = x;
        int ans = 0;
        while(num != 0){
            int dig = num%10;
            ans = ans*10 + dig;
            num = num/10;
        }
        return (x == ans);
    }
}