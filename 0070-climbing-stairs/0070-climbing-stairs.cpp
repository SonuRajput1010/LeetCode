class Solution {
public:
    int climbStairs(int n) {
        int a =0;
        int b= 1;
        for(int i=0; i<n; i++){
            int temp = a+b;
            a=b;
            b= temp;
        }
        return b;
    }
    
};