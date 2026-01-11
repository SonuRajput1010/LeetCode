class Solution {
    public int[] twoSum(int[] nums, int target) {

        int n = nums.length;
        int[][] ans = new int[n][2];

        for(int i=0; i<n; i++) {
            ans[i][0] = nums[i];
            ans[i][1] = i;
        }
        Arrays.sort(ans , (a,b)->Integer.compare (a[0],b[0]));
        int i=0;
        int j=n-1;

        while(i<j){
            int sum = ans[i][0] + ans[j][0];
            if(sum == target) return new int[]{ans[i][1], ans[j][1]};
            if(sum > target) j--;
            else i++;

        }
        return new int[]{-1, -1};
    }
}