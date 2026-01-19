class Solution {
    public int addDigits(int num) {

        int x = num;

        while(x >=10){

            int sum =0;

            while(x != 0){
            int dig = x%10;
            sum += dig;
            x /= 10;
            }

            x = sum;
        }
        return x;
    }
}