class Solution {
    public double myPow(double x, int n) {
        
        long exp = n;

        if(exp < 0){
            exp = -exp;
        }

        double ans = 1;

        while(exp > 0){
            if(exp%2 != 0){
                ans *= x;
            }
            x *= x;
            exp /= 2;
        }
         if (n < 0) {
            ans = 1.0 / ans;
        }
 
        return ans;
    }
}