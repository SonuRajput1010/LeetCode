class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        List<int[]> result = new ArrayList<>();
        int n = intervals.length;
        int start = newInterval[0];;
        int end = newInterval[1];

        int i=0;
        while(i < n && intervals[i][1] < start ){
            result.add(intervals[i]);
            i++;
        }

        while( i<n && intervals[i][0] <= end){
            start = Math.min(intervals[i][0],start);
            end = Math.max(intervals[i][1],end);
            i++;
        }
        result.add(new int[]{start,end});

        while (i < n) {
            result.add(intervals[i]);
            i++;
        }
        return result.toArray(new int[result.size()][]);
    }
}