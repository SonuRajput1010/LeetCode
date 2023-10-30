//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string solve(int arr[], int n) {
        // code here
        sort(arr,arr+n);
        string s1="",s2="";
        for(int i=0;i<n;i++){
            if(i%2==0)
                s1+=arr[i]+'0';
            else
                s2+=arr[i]+'0';
        }
        string ans="";
        int l1=s1.length()-1;
        int l2=s2.length()-1;
        int carry=0;
        while(l1>=0&&l2>=0){
            int x=s1[l1--]-'0';
            int y=s2[l2--]-'0';
            int res=(x+y+carry)%10;
            carry=(x+y+carry)/10;
            ans+=res+'0';
        }
        while(l1>=0){
            ans+=(arr[l1--]+carry)+'0';
            carry=0;
            
        }
        while(l2>=0){
            ans+=(arr[l2--]+carry)+'0';
            carry=0;
        }
        if(carry!=0){
        ans+=carry+'0';
        }
        reverse(ans.begin(),ans.end());
        int i=0;
        while(ans[i]=='0')
        {
            ans.erase(i,1);
        }
       return ans.empty()  ? "0" :ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends