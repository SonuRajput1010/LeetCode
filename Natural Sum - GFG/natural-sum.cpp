//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
	public:
	int getFind(int n, int i,int count){
        if(i>n){
            return -1;
        }
        if(i == n){
            return count;
        }
        count = count+1;
        int sum = i + count;
        return getFind(n,sum,count);
    }
   	int find(int n){
   	    // Code here
   	    int sum = getFind(n,1,1);
   	    return sum;
   	}    
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.find(n);
		cout << ans <<"\n";
	}  
	return 0;
}
// } Driver Code Ends