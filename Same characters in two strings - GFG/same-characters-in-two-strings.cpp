//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int sameChar(string A, string B)
    {
        // code here 
        int n = A.length();
        int count = 0;
        
        for(int i=0; i<n; i++)
        {
            A[i] = tolower(A[i]);
            B[i] = tolower(B[i]);
        }
        
        for(int i=0; i<n; i++){
            if(A[i] == B[i]){
                count++;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;
        Solution ob;
        cout<<ob.sameChar(A,B)<<endl;
    }
    return 0;
}
// } Driver Code Ends