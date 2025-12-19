class Solution {
    public int candy(int[] ratings) {

        int n = ratings.length;
        int[] left = new int[n];

        left[0] = 1;
        for(int i=1; i<n; i++){
            if( ratings[i] > ratings[i-1]){
                left[i] = left[i-1]+1;
            }
            else{
                left[i] = 1;
            }
        }

        int sum = 0;
        int curr = 1;
        int right = 1;

        for(int i = n-2; i>=0; i--){
            if( ratings[i] > ratings[i+1]){
                curr = right +1;
                right = curr;
            }
            else{
                curr = 1;
                right = 1;
            }
            sum += Math.max(left[i],curr);
        }
            sum = sum + Math.max(left[n-1],1);

        return sum;
    }
}