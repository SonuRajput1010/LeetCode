class Solution {
    public int climbStairs(int n) {
         int prev0 = 1;
        int prev1 = 2;

        if( n == 1) return prev0;
        if(n== 2) return prev1;

        int temp = 0;

        for(int i=3; i<=n; i++ ){
            temp = prev0 + prev1;
            prev0 = prev1;
            prev1 = temp;
        }
        return prev1;
    }
}