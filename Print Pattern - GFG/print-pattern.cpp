//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> helper(vector<int> v,int N){
       v.push_back(N);
       if(N <= 0){
           return v;
       }
       vector<int> ans = helper(v,N-5);
        ans.push_back(N);
        return ans;
    }
    
    vector<int> pattern(int N){
        // code here
        
        vector<int> v;
        return helper(v,N);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.pattern(N);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends