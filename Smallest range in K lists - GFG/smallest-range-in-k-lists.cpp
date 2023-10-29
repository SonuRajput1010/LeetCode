//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


// } Driver Code Ends
// you are required to complete this function 
// function should print the required range
class Solution{
    public:
    class Node{
      public:
        int data;
        int row;
        int col;
        Node(int d, int row, int col){
            this -> data = d;
            this -> row = row;
            this -> col = col;
        }
    };
    class compare{
      public:
        bool operator()(Node* a, Node* b)
        {
            return a -> data > b -> data;
        }
    };
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
          //code here
          int maxi = INT_MIN;
          int mini = INT_MAX;
          priority_queue< Node*, vector<Node*>, compare > minHeap;
          
          for(int i=0; i<k; i++){
              int element = KSortedArray[i][0];
              mini = min(mini,element);
              maxi = max(maxi,element);
              minHeap.push(new Node(element,i,0));
          }
          int start = mini; 
          int end = maxi;
          
          while(!minHeap.empty()){
              
              Node* temp = minHeap.top();
              minHeap.pop();
              
              mini = temp->data;
              
              if(maxi-mini < end-start){
                  start = mini;
                  end = maxi;
              }
              
              if(temp->col+1 < n){
                  maxi = max(maxi,KSortedArray[temp->row][temp->col + 1]);
                  minHeap.push(new Node(KSortedArray[temp->row][temp->col + 1],temp->row, temp->col+1));
              }
              else{
                  break;
              }
          }
          
          return {start,end};
          
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}


// } Driver Code Ends