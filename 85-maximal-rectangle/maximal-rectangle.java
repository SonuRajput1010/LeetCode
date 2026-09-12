class Solution {
    public int largestRectangleArea(int[] heights) {
        int n = heights.length;
        int maxArea = 0;
        Stack<Integer> st = new Stack<>();

        for(int i=0; i<=n; i++){
            int h = (i == n) ? 0 : heights[i];

            while(!st.isEmpty() && heights[st.peek()] > h){
                int height = heights[st.pop()];
                int weight = st.isEmpty() ? i : i-st.peek()-1;

                int area = height * weight;

                maxArea = Math.max(maxArea,area);
            }
            st.push(i);
        }
        return maxArea;
    } 
    public int maximalRectangle(char[][] matrix) {
        int rows = matrix.length;
        int cols = matrix[0].length;

        int[] heights = new int[cols];
        int maxArea = 0;

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(matrix[i][j] == '1') heights[j] += 1;
                else heights[j] = 0;
            }
            maxArea = Math.max(maxArea,largestRectangleArea(heights));
        }
        return maxArea;
    }
}