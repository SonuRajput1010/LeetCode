class Solution {
    public long maxMatrixSum(int[][] matrix) {
        int n = matrix.length;

        long sum = 0;
        int negCount = 0;
        int minAbsoluteValue = Integer.MAX_VALUE;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){

                sum += Math.abs(matrix[i][j]);

                if(matrix[i][j] < 0){
                    negCount++;
                }

                minAbsoluteValue = Math.min(minAbsoluteValue,Math.abs(matrix[i][j]));
            }
        }

        if( negCount %2 == 0) return sum;

        return sum - 2*minAbsoluteValue;
    }
}