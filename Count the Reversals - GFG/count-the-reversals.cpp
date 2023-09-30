//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int countRev (string str)
{
    // your code here
    int n = str.size();
    
    int a = 0 , b = 0;
    
    if(n%2 == 1){
        return -1;
    }
    
    stack<char>st;
    
    for(int i =0;i<n;i++){
        char ch =str[i];
        
        if(ch == '{'){
            st.push(ch);
            a++;
        }
        else{
            // closed bracket will be there
            
            if(!st.empty() && st.top() =='{' ){
                st.pop();
                --a;
            }
            else{
                b++;
                st.push(ch);
            }
        }
    }
    
    
    int ans = (a+1)/2 + (b+1)/2;
    return ans;
    
}