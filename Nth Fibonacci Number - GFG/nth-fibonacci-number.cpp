//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
      int nthFibonacci(int n){
if(n==1|| n==2){
    return 1;
}
long long  arr[n];
   arr[0]=1;
   arr[1]=1;
   
      long long mod = 1e9 + 7;
   for( long long  i=2;i<n;i++){
       arr[i]=(arr[i-1]+arr[i-2])%mod;
   }
   return (int)arr[n-1];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends