class Solution {
    public int dayCalc(int[] weights, int cap ){

        int load = 0;
        int days = 1;

        for(int w : weights){
            if( w + load > cap){
                days += 1;
                load = w;
            }
            else{
                load += w;
            }
        }
        return days;
    }
    public int shipWithinDays(int[] weights, int days) {
        
        int maxi = 0;
        int sum = 0;

        for(int w : weights){
            sum += w;
            maxi = Math.max(w,maxi);
        }

        int low = maxi;
        int high = sum;

        while(low <= high){
            int mid = low + (high-low)/2;
            int daysTaken = dayCalc(weights,mid);
            if(daysTaken <= days){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
}