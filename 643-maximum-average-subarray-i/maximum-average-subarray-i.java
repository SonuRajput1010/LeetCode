class Solution {
    public double findMaxAverage(int[] nums, int k) {

        int n = nums.length;
        int i = 0;
        double sum = 0;
        double maxAvg = 0;

        for(int j=0; j<k; j++){
            sum  += nums[j];
        }

        maxAvg = sum/k;

        for(int x = k; x<n; x++){

            sum += nums[x];
            sum -= nums[i];

            double avg = sum/k;


            maxAvg = Math.max(avg,maxAvg);

            i++;
        }
        return maxAvg;

        
    }
}