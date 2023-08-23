//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
      if(N==0){
          return 0;
      }
      int longest =1;
      
      unordered_set <int> ans;
      for(int i=0; i<N; i++){
          ans.insert(arr[i]);
      }
      for(auto it : ans ){
          if(ans.find(it-1) ==  ans.end()){
              int cnt = 1;
              int x = it;
              while(ans.find(x+1) != ans.end()){
                  x++;
                  cnt++;
              }
              longest = max(longest,cnt);
          }
      }
      return longest;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends