class Solution {
    public int[][] matrixBlockSum(int[][] mat, int k) {

        int n = mat.length;
        int m = mat[0].length;

        int[][] prefixSum = new int[n + 1][m + 1];

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                prefixSum[i][j] =
                        mat[i - 1][j - 1]
                        + prefixSum[i - 1][j]
                        + prefixSum[i][j - 1]
                        - prefixSum[i - 1][j - 1];
            }
        }

        int[][] ans = new int[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                int r1 = Math.max(0, i - k);
                int c1 = Math.max(0, j - k);

                int r2 = Math.min(n - 1, i + k);
                int c2 = Math.min(m - 1, j + k);

                r1++;
                c1++;
                r2++;
                c2++;

                ans[i][j] =
                        prefixSum[r2][c2]
                        - prefixSum[r1 - 1][c2]
                        - prefixSum[r2][c1 - 1]
                        + prefixSum[r1 - 1][c1 - 1];
            }
        }

        return ans;
    }
}