//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int>s;
        
        //push all elemnt in stack
        for(int i=0; i<n; i++){
            s.push(i);
        }
        
        //step 2 check if a knows b  or b knows a
        while( s.size() > 1){
            int a = s.top();
            s.pop();
            
            int b = s.top();
            s.pop();
            
            if( M[a][b]== 1 ){
                s.push(b);
            }
            else {
                s.push(a);
            }
        }
        
        // single element in stack is a potential ccelebrity
        // so verify it
        int ans = s.top();
        
        // row check
        bool rowCheck = false;
        int zeroCount =0;
        
        for( int i =0 ; i<n ; i++){
            if( M [ans][ i ] == 0 ){
                zeroCount ++;
            }
        }
        if( zeroCount == n){
            rowCheck = true;
        }
        
        // column check
        bool colCheck = false;
        int oneCount =0;
        
        for( int i =0 ; i<n ; i++){
            if( M [ i ][ ans ] == 1 ){
                oneCount ++;
            }
        }
        if( oneCount == n-1){
            colCheck = true;
        }
        
        if( colCheck && rowCheck)
            return ans;
        else
            return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends