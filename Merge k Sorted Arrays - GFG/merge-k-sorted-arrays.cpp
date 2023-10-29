//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    
    class Node{
      public:
        int data;
        int row;
        int col;
        Node(int a, int row, int col){
            this -> data = a;
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
    
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        //code here
        priority_queue<Node*, vector<Node*>, compare> minHeap;
        
        // insert first element of all the arrays;
        for(int i=0; i<k; i++){
            Node* temp = new Node(arr[i][0],i,0);
            minHeap.push(temp);
        }
        
        // ans array
        vector<int>ans;
        while(minHeap.size() > 0)
        {
            Node* temp = minHeap.top();
            ans.push_back(temp -> data);
            minHeap.pop();
            int row = temp -> row;
            int col = temp -> col;
            if(col + 1 < arr[row].size())
            {
                Node* next = new Node(arr[row][col + 1], row, col + 1);
                minHeap.push(next);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends