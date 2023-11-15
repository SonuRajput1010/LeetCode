//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    void solve(int a[], int n, string s, int index, vector<string>& ans, vector<string>& mapping){
        //Base case
        if(index == n){
            ans.push_back(s);
            return ;
        }
        
        int number= a[index];
        string value=mapping[number];
        
        for(int i=0; i<value.length(); i++){
            s.push_back(value[i]);
            solve(a, n, s, index+1, ans, mapping);
            s.pop_back();
        }
    }
    vector<string> possibleWords(int a[], int N)
    {
        //Your code here
        vector<string>ans;
        if(N == 0){
            return ans;
        }
        
        string output = "";
        int index = 0;
        
        vector <string> mapping= {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(a,N,output,index,ans,mapping);
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}
// } Driver Code Ends