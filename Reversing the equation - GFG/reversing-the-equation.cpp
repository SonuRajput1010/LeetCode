//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s)
        {
            //code here.
            string rev ="";
            stack<char>st;
            int i = s.size()-1;
            
            while(i>=0){
                if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' ){
                    while(!st.empty()){
                        char tp = st.top();
                        rev += tp;
                        st.pop();
                    }
                    rev += s[i];
                }
                else{
                    st.push(s[i]);
                }
                i--;
            }
            while(!st.empty()){
                char tp = st.top();
                rev += tp;
                st.pop();
            }
            return rev;
            
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends