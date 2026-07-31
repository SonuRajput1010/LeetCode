class Solution {
    public int[][] merge(int[][] intervals) {
        int n = intervals.length;
        Arrays.sort(intervals,(a,b)->Integer.compare(a[0],b[0]));

        int[][] ans = new int[n][2];

        ans[0][0] = intervals[0][0];
        ans[0][1] = intervals[0][1];
        int index =0;

        for(int i=1; i<n; i++){
            if(intervals[i][0] <= ans[index][1] ){
                ans[index][1] = Math.max(ans[index][1],intervals[i][1]) ;
                
            }
            else{
                index++;
                ans[index][0] =  intervals[i][0];
                ans[index][1] =  intervals[i][1];
                
            }

        }
        return Arrays.copyOf(ans,index+1);
    }
}