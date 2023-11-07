//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int fib(int n){
        //code here
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 1;
        int a=1,b=1,c;
        for(int i=3;i<=n;i++){
            c=(a+b)%10;
            a=b; b=c;
        }
        return c;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.fib(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends