//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int firstOccurrences(int arr[], int n , int key ){
        
        int low = 0;
        int high = n - 1;
        int first = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == key) {
                first = mid;
                high = mid-1;
            }
            else if(arr[mid] < key) {
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return first;
    }
    int lastOccurrences(int arr[], int n , int key ){
        
        int start = 0;
        int end = n - 1;
        int last = -1;
        
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] == key) {
            last = mid;
            start = mid + 1;
            
            } 
            else if (key < arr[mid]) {
                end = mid - 1;
                } 
            else {
                start = mid + 1;
                }
            }
            return last;
        }
    
    vector<int> find(int arr[], int n , int x )
    {
        // code here
        int first = firstOccurrences(arr,n,x);
        if(first == -1){
            return {-1,-1};
        }
        int last  = lastOccurrences(arr,n,x);
        return {first,last};
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends