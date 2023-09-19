//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
    public:
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int a[], int n){
        
        long long sum = 0, maxi = a[0];
        
        //Iterating over the array.
        for(int i=0;i<n;i++) 
            {
                //Updating max sum till current index.
                sum+=a[i];
                //Storing max sum so far by choosing maximum between max 
                //sum so far and max till current index.
                if(maxi<sum)
                maxi=sum; 
                
                //If max sum at current index is negative, we do not need to add
                //it to result so we update it to zero.
                if(sum<0)
                    sum=0;
    
            }
            //returning the result.
            return maxi;
        
    }
};


//{ Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}

// } Driver Code Ends