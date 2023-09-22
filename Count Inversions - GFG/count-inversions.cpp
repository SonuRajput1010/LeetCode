//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
     long long int MergeAndCount(long long arr[], long long temp[], int left, int mid, int right) {
        int i = left;
        int j = mid; 
        int k = left; 
        long long int inversionCount = 0;
        while (i <= mid - 1 && j <= right) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                 temp[k++] = arr[j++];
                inversionCount += (mid - i); 
            }
        }
        while (i <= mid - 1) {
            temp[k++] = arr[i++];
        }
        while (j <= right) {
            temp[k++] = arr[j++];
        }
        for (i = left; i <= right; i++) {
            arr[i] = temp[i];
        }
        return inversionCount;
    }
    
    long long int MergeSortAndCount(long long arr[], long long temp[], int left, int right) {
        long long int inversionCount = 0;
        if (left < right) {
            int mid = (left + right) / 2;
            inversionCount += MergeSortAndCount(arr, temp, left, mid);
            inversionCount += MergeSortAndCount(arr, temp, mid + 1, right); 
            inversionCount += MergeAndCount(arr, temp, left, mid + 1, right); 
        }
        return inversionCount;
    }

    long long int inversionCount(long long arr[], long long N) {
        long long temp[N];
        return MergeSortAndCount(arr, temp, 0, N - 1);
    }
};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends