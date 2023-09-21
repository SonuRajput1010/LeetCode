//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
    
          // Optimal solution2
          
        void swapIfGreater(long long arr1[], long long arr2[], int ind1, int ind2) {
            if (arr1[ind1] > arr2[ind2]) {
                swap(arr1[ind1], arr2[ind2]);
            }
        }

        void merge(long long arr1[], long long arr2[], int n, int m) {
            
            int len = n + m;
            int gap = (len / 2) + (len % 2);
        
            while (gap > 0) {
                // Place 2 pointers:
                int left = 0;
                int right = left + gap;
                while (right < len) {
                    if (left < n && right >= n) {
                        swapIfGreater(arr1, arr2, left, right - n);
                    }
                    // case 2: both pointers in arr2[]:
                    else if (left >= n) {
                        swapIfGreater(arr2, arr2, left - n, right - n);
                    }
                    // case 3: both pointers in arr1[]:
                    else {
                        swapIfGreater(arr1, arr1, left, right);
                    }
                    left++, right++;
                }
                // break if iteration gap=1 is completed:
                if (gap == 1) break;
        
                // Otherwise, calculate new gap:
                gap = (gap / 2) + (gap % 2);
            }
        }
};
  
        // Optimal solution1
        
        //  void merge(long long arr1[], long long arr2[], int n, int m) 
        // { 
        //     // code here 
        //     int left = n-1;
        //     int right = 0;
            
        //     while(left>=0 && right<m){
        //         if(arr1[left] > arr2[right] ){
        //             swap(arr1[left--] , arr2[right++]);
        //         }
        //         else{
        //             break;
        //         }
        //     }
            
        //     sort(arr1,arr1+n);
        //     sort(arr2,arr2+m);
        // } 

//{ Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 

// } Driver Code Ends