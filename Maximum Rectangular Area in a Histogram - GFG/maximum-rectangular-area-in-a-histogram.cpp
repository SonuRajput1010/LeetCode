//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    private:
    vector<int> nextSmallerElement(long long arr[], int n){
        
        vector<int> ans(n); 
        stack<int> s;
        s.push(-1);
	    
	    for(int  i=n-1; i >= 0; i--){
            while(s.top() != -1 && arr[s.top()] >= arr[i]){
                s.pop();
            }
            
                ans[i] = s.top();
                s.push(i);
	    }
	    return ans;
    }
    vector<int> prevSmallerElement(long long arr[], int n){
        
        vector<int> ans(n); 
        stack<int> s;
        s.push(-1);
	    
	    for(int i = 0; i<n; i++){
            while(s.top() != -1 && arr[s.top()] >= arr[i]){
                s.pop();
            }
            
                ans[i] = s.top();
                s.push(i);
	    }
	    return ans;
    }

    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        vector<int>next(n);
        next = nextSmallerElement(arr,n);
        
        vector<int>prev(n);
        prev = prevSmallerElement(arr,n);
        
        long long area = INT_MIN;
        
        for(int i=0; i<n; i++){
            long long l = arr[i];
            
            if(next[i] == -1){
                next[i] = n;
            }
            
            long long b = next[i]-prev[i]-1;
            
            long long newArea = l*b;
            area = max(newArea,area);
        }
        return area;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends