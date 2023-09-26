//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> nums, int n) {
        // code here
        
        
        long long sum = 0, sqrSum = 0;
    long long val;

    for (int i = 0; i < n; i++)
    {
        val = nums[i];

        // Adding nums[i] to the sum.
        sum += val;

        // Simultaneously subtracting the (i+1)th positive integer from the sum.
        sum -= (i + 1);

        // Adding square of nums[i] to the sum of squares.
        sqrSum += (val * val);

        // Simultaneously subtracting the square of (i+1)th positive integer from the sum.
        sqrSum -= ((long long)(i + 1) * (long long)(i + 1));
    }

    // X is repeating number, Y is missing number.
    long long xPlusY = sqrSum / sum;
    long long xMinusY = sum;

    int x = (int)((xPlusY + xMinusY) / 2);
    int y = xPlusY - x;

    vector<int> ans;
    ans.push_back(x);
    ans.push_back(y);

    return ans;
    }
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends