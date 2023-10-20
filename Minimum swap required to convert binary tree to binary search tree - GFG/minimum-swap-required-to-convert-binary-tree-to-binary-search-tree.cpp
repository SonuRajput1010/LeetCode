//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
  public:
  
//   Approach

// Find the inorder store it an array.
// Find minimum swaps required to sort the inorder(array).

// We have an inorder vector called "in".
// Make another vector temp which is copy of "in".
// Sort temp.
// Make a map called mapping in which we store each element of "in" along with their indices.
// Traverse both arrays , if elements at a particular index are no equal in both arrays , 
//     increment the ans variable, swap the elements in "in" vector and update mappings.

    void inorder(vector<int>A,int i, vector<int>&in){
        if(i>A.size()-1){
            return;
        }
        inorder(A,2*i+1,in);
        in.push_back(A[i]);
        inorder(A,2*i+2,in);
    }
    
    void swaping(vector<int>&nums,int i,int j){
        swap(nums[i],nums[j]);
    }
    int minSwaps(vector<int>&A, int n){
        //Write your code here
        vector<int>in;
        inorder(A,0,in);
        vector<int>temp = in;
        sort(temp.begin(),temp.end());
        
        unordered_map<int,int>mp;
        
        for(int i=0; i<in.size(); i++){
            mp[in[i]] = i;
        }
        
        int swap = 0;
        
        for(int i=0; i<in.size(); i++){
            if(in[i] != temp[i]){
                swap++;
                int x = in[i];
                swaping(in,i,mp[temp[i]]);
                
                mp[x] = mp[temp[i]];
                mp[in[i]] = i;
            }
        }
        return swap;
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
	    cin >> n;
	    vector<int>A(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> A[i];
	    }
	    Solution ob;
	    int ans = ob.minSwaps(A, n);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends