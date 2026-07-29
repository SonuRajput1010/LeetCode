class Solution {
    public int maxProduct(int[] nums) {
        
        int n = nums.length;
        int[] prodArr = new int[nums.length];
        int pref = 1;
        int suff = 1;
        int ans = Integer.MIN_VALUE;

        for(int i=0; i<n; i++){
            
            if(pref == 0) pref = 1;
            if(suff == 0) suff = 1;

            pref *= nums[i];
            suff *= nums[n-i-1];

            ans = Math.max(ans,Math.max(pref,suff));
        }
        return ans;

    }
}