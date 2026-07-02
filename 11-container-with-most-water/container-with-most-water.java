class Solution {
    public int maxArea(int[] height) {

        int n = height.length;
        int l = 0;
        int r = n-1;
        int maxArea = 0;

        int h = 0;
        int w = 0;

        while(l<r){
            h = Math.min(height[l],height[r]);
            w = r-l;
            int area = h * w;
            maxArea = Math.max(area,maxArea);

            if(height[l] <= height[r]) l++;
            else r--;
        }
        return maxArea;
        
    }
}