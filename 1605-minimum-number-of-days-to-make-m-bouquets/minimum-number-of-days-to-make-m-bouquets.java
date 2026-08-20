class Solution {
    public boolean possibelBouquets(int arr[], int m, int k, int mid){
        int cntBouquets = 0;
        int cnt = 0;

        for(int i=0; i<arr.length; i++){
            if(arr[i] <= mid){
                cnt++;
            }
            else{
                cntBouquets += cnt /k;
                cnt = 0;
            }
        }
        cntBouquets += cnt / k;

        return cntBouquets >= m;
    }
    public int minDays(int[] bloomDay, int m, int k) {
        
        int n = bloomDay.length;

        if((long)m * k > n) return -1;

        int mini = Integer.MAX_VALUE;
        int maxi = Integer.MIN_VALUE;


        for(int x : bloomDay){
           mini = Math.min(mini,x);
           maxi = Math.max(maxi,x);
        }

        int low = mini;
        int high = maxi;

        while(low <= high){
            int mid = low + (high-low)/2;

            if(possibelBouquets(bloomDay, m, k, mid)){
                high = mid-1;
            }
            else low = mid+1;
        }
        return low;
    }
}