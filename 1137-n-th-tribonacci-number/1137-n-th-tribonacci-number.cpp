class Solution {
public:
int dp[38];
  int fib1(int n){
      if(n==0)return dp[n]=0;
      if(n==1 or n==2)return dp[n]=1;
      
     if(dp[n]!=-1)return dp[n];

      return dp[n]=fib1(n-1)+fib1(n-2)+fib1(n-3);
  }
    int tribonacci(int n) {
        memset(dp,-1,sizeof(dp));
        return fib1(n);
    }
};