//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to insert heap.
    priority_queue<int> maxheap;
    priority_queue<int , vector<int> , greater<int>> minheap;
    int median =0;
    void insertHeap(int &x)
    {
        minheap.push(x);
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        int ele = minheap.top();
        minheap.pop();
        if(maxheap.size() == minheap.size()){
         if(ele > median){
             minheap.push(ele);
             median = minheap.top();
             }
             else{
                 maxheap.push(ele);
                 median = maxheap.top();
             }
         }
         else if(maxheap.size() > minheap.size()){
             if(ele > median){
                 minheap.push(ele);
                 median = (maxheap.top()+minheap.top())/2;
             }
             else{
                 minheap.push(maxheap.top());
                 maxheap.pop();
                 maxheap.push(ele);
                 median = (maxheap.top() + minheap.top())/2;
             }
         }
         else{
             if(ele > median){
                 maxheap.push(minheap.top());
                 minheap.pop();
                 minheap.push(ele);
                 median = (maxheap.top() + minheap.top())/2;
             }
             else{
                 maxheap.push(ele);
                 median = (maxheap.top() + minheap.top())/2;
             }
         }
        
    }
    
    //Function to return Median.
    double getMedian()
    {
        return median;
    }
};


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
// } Driver Code Ends