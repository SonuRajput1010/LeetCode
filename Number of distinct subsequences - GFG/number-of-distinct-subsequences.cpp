//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:	
	int distinctSubsequences(string s)
	{
	    // Your code goes here
	    int n = s.length();
	    int mod = 1e9 + 7;
	    vector <int> dp(n+1);
	    dp[0]=1;
	    
	    unordered_map<char,int>last_occu;
	    
	    for(int i=1; i<=n; i++){
	        
	        dp[i] = (2*dp[i-1]) % mod;
	        char ch = s[i-1];
	        
	        if(last_occu.find(ch) != last_occu.end()){
	            int j = last_occu[ch];
	            dp[i] = ( dp[i]-dp[j-1]+mod ) %mod;
	        }
	        last_occu[ch] = i;
	    }
	    return dp[n];
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends