class Solution {
    public int trap(int[] height) {

        int n = height.length;
        int l=0,r=n-1;
        int l_max = height[l], r_max = height[r];
        int totalWater = 0;

        while(l<r){
            if(l_max < r_max){
                l++;
                l_max = Math.max(l_max,height[l]);
                totalWater += l_max - height[l];
            }
            else{
                r--;
                r_max = Math.max(r_max,height[r]);
                totalWater += r_max - height[r];
            }
        }
        return totalWater;        
    }
}