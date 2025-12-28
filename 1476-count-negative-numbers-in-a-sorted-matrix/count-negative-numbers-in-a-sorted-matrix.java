class Solution {
    public int countNegatives(int[][] grid) {
        int row = grid.length;
        int col = grid[0].length;


        int r = 0;
        int c = col-1;
        int count = 0;

        while(r<row && c >=0){
            if(grid[r][c] < 0){
                count += row-r;
                c--;
            }
            else{
                r++;
            }
        }
        return count;
    }
}