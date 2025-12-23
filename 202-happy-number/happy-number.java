class Solution {
    public int squareSum(int n){
        int sum =0;
        while(n > 0){
            int d = n%10;
            sum += d * d;
            n /= 10;
        }
        return sum;
    }
    public boolean isHappy(int n) {

        int slow = n;
        int fast = n;

        while(true){
            slow = squareSum(slow);

            fast = squareSum(fast);
            fast = squareSum(fast);

            if(fast == 1) return true;
            if(slow == fast ) return false; // cycle 

        }
        
    }
}