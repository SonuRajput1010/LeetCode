class Solution {
    public int uniquePaths(int m, int n) {

        int dp[][] = new int[m][n];
        return countPath(m-1,n-1,dp);
    }
    public int countPath(int m, int n, int[][] dp){

        if(m==0 || n==0) return 1;

        if(dp[m][n] != 0) return dp[m][n];


        dp[m][n] = countPath(m-1,n,dp)+countPath(m,n-1,dp);

        return dp[m][n];

    }
        // TLE due to recursion taking exponential power as it is  non linear recursion. 

    //     return countPath(m-1,n-1);
    // }
    // public int countPath(int m, int n){
    //     if(m==0 || n==0) return 1;
    //     return countPath(m-1,n)+countPath(m,n-1);
    // }
}