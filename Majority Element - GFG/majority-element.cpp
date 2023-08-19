//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        
        // your code here
        int cnt =0;
        int element ;
        for(int i=0; i<size; i++){
            if(cnt == 0){
                cnt = 1;
                element = a[i];
            }
            else if(a[i] == element){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        int count=0;
        for(int i=0; i<size; i++){
            if(a[i] == element)
                count++;
        }
        if(count > (size/2)){
            return element;
        }
        else{
            return -1;
        }
        
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends