class Solution {
    public long maximumHappinessSum(int[] happiness, int k) {
        int n = happiness.length;
        Arrays.sort(happiness);
        long ans = 0;
        int c =0;

        for(int i=n-1; (i>=0 && k>0); k--,i-- ){
            int val = happiness[i]-c;

            if(val > 0){
                ans += val;
            }
            c++;
        }
        return ans;
    }
}