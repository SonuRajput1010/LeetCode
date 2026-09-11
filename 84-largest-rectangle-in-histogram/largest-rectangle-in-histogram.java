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
}