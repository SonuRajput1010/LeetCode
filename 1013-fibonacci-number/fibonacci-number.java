class Solution {
    public int fib(int n) {

        int prev0 = 0;
        int prev1 = 1;

        if( n == 0) return prev0;
        if(n== 1) return prev1;

        int temp = 0;

        for(int i=2; i<=n; i++ ){
            temp = prev0 + prev1;
            prev0 = prev1;
            prev1 = temp;
        }
        return prev1;

        // if(n == 0) return 0;
        // if(n== 1) return 1;

        // return fib(n-1)+fib(n-2);
    }
}